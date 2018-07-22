# 120. Word Ladder

## Description
~~~
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

1. Only one letter can be changed at a time
2. Each intermediate word must exist in the dictionary
```
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
```
~~~

**Example**
```
Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
```

## Link
[lintcode](https://lintcode.com/problem/word-ladder/)

## Method
Permuation problem
1. DFS by recursion  - this will cause time complexity exceed limit since it searchs all permutations
key point: check diagnol positions  

2. BFS - it's actually an issue of shortest distance of a graph
## Solution
1.1 DFS (time complexity exceed limitations O(26^L))
~~~
class Solution {
public:
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: An integer
     */
    int ladderLength(string &start, string &end, unordered_set<string> &dict) {
        // write your code here
        shortest = INT_MAX;
        dict.insert(start);
        dict.insert(end);
        dfsHelper(start, end, dict, 1);
        return shortest;
    }
    
    void dfsHelper(string &start, string &end, unordered_set<string> &dict, int steps) {
        if (!start.compare(end)) {
            if (steps < shortest) {
                shortest = steps;
            }
            return;
        }
        
        for(int i = 0; i < end.length(); i++) {
            char curChar = start[i];
            for(char nextChar = 'a'; nextChar <= 'z'; nextChar++) {
                if (curChar == nextChar) {
                    continue;
                }
                
                start[i] = nextChar;
                if (dict.find(start) != dict.end()) {
                    dict.erase(start);
                    dfsHelper(start, end, dict, steps+1);
                    dict.insert(start);
                }
            }
            start[i] = curChar;
        }
        
    }

private:
    int shortest;
};
~~~ 

1.2 BFS (O())
~~~
class Solution {
public:
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: An integer
     */
    int ladderLength(string &start, string &end, unordered_set<string> &dict) {
        // write your code here
        // BFS to search graph
        if (start == end) {
            return 1;
        }
        
        if (start.size() == 0 || start.size() != end.size()) {
            return 0;
        }
        
        queue<string> q;
        q.push(start);
        int len = start.size();
        int minLength = 1;
        
        while(!q.empty()) {
            int size = q.size();
            
            for(int i = 0; i < size; i ++) {
                string word = q.front();
                q.pop();
                if (word == end) {
                    return minLength;
                }

                // find all current string neighbors
                for(int j = 0; j < len; j++) {
                    char oldChar = word[j];
                    for(char c = 'a'; c <= 'z'; c++) {
                        if (oldChar == c) {
                            continue;
                        }
                        word[j] = c;
                        if (dict.find(word) != dict.end()) {
                            q.push(word);
                            dict.erase(word);
                        }
                    }
                    word[j] = oldChar;
                }
            }
            minLength++;
        }
        
        return minLength;
    }
};
~~~


## Similar problems
[Permutations](https://lintcode.com/problem/word-ladder-ii/)

## Tags
BFS
DFS  
Permutation
