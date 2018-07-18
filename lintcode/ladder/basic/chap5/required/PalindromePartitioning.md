# 136. Palindrome Partitioning

## Description
~~~
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.
~~~

**Example**
```
Given s = "aab", return:

[
  ["aa","b"],
  ["a","a","b"]
]
```

## Link
[lintcode](https://lintcode.com/problem/palindrome-partitioning/)

## Method
1. DFS 
Key point: DFS templated for subset - 3 key points for a recursion function (function signature, exit condition, body part)  
##optimization (DP)

## Solution
1.1 DFS
~~~
class Solution {
public:
    /*
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string &s) {
        // write your code here
        vector<vector<string>> result;
        int size = s.size();
        if (size == 0) {
            return result;
        }
    
        vector<string> solution;
        
        dfs(result, solution, s, 0);
        
        return result;
    }
    
    void dfs(vector<vector<string>> &result, vector<string> &partitions, string &s, int pos) {
        
        if (pos == s.size()) {
            result.push_back(partitions);
            return;
        }
        
        string record="";
        for(int i = pos; i < s.size(); i++) {
            record += s[i];
            // can be optimized in advance for O(1) to determine if string is Palindrome
            if (isPalindrom(record)) {
                partitions.push_back(record);
                dfs(result, partitions, s, i+1);
                solution.pop_back();
            }
        }
    }
    
    bool isPalindrom(string &s) {
        if (s.empty()) {
            return true;
        }
        
        int i = 0, j = s.size() -1;
    
        for(int i = 0, j = s.size()-1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }

        return true;
    }
};

// DP optimization
 void getIsPalindrome(string s) {
    int n = s.length();
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        
    for (int i = 0; i < n; i++) {
        isPalindrome[i][i] = true;
    }
    for (int i = 0; i < n - 1; i++) {
        isPalindrome[i][i + 1] = (s[i] == s[i + 1]);
    }
        
    for (int i = n - 3; i >= 0; i--) {
        for (int j = i + 2; j < n; j++) {
            isPalindrome[i][j] = isPalindrome[i + 1][j - 1] && s.[i] == s[j];
        }
    }
}
    
~~~

## Similar problems
[Combination Sum II](https://lintcode.com/problem/palindrome-partitioning-ii/)

## Tags
DFS 
