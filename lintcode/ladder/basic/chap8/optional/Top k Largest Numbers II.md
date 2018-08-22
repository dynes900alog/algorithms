# 545. Top k Largest Numbers II

## Description

Implement a data structure, provide two interfaces:

1. add(number). Add a new number in the data structure.
2. topk(). Return the top k largest numbers in this data structure. k is given when we create the data structure.

##Example##
Example
```
s = new Solution(3);
>> create a new data structure.
s.add(3)
s.add(10)
s.topk()
>> return [10, 3]
s.add(1000)
s.add(-99)
s.topk()
>> return [1000, 10, 3]
s.add(4)
s.topk()
>> return [1000, 10, 4]
s.add(100)
s.topk()
>> return [1000, 100, 10]
```
## Link
[lintcode](https://www.lintcode.com/problem/top-k-largest-numbers-ii/)

## Method
* Min Heap (save data) + Max Heap (Retrieve data)  
  * Time complexity: add - O(logK) topK - O(klogk)
  * Space: O(k)

## Solution
1.1 Doubly Linked List + Hash
~~~
// Space O(k)

class Solution {
private:
    int capacity;
    priority_queue<int, vector<int>, std::greater<int>> minpq;
    priority_queue<int, vector<int>, std::less<int>> maxpq;

public:
    /*
    * @param k: An integer
    */
    Solution(int k) {
        // do intialization if necessary
        capacity = k;
        // min-heap

    }

    /*
     * @param num: Number to be added
     * @return: nothing
     */
    // O(logK) 
    void add(int num) {
        // write your code here
        if (minpq.size() < capacity) {
            minpq.push(num);
        }
        else {
            int min = minpq.top();
            if (num > min) {
                minpq.pop();
                minpq.push(num);
            }
        }
    }

    /*
     * @return: Top k element
     */
    // O(klogK)
    vector<int> topk() {
        // write your code here
        vector<int> result;
        while(!minpq.empty()) {
            int value = minpq.top();
            minpq.pop();
            maxpq.push(value);
        }
        
        while (!maxpq.empty()) {
            int value = maxpq.top();
            result.push_back(value);
            minpq.push(value);
            maxpq.pop();
        }
        return result;
    }
};
~~~

## Similar problems
[Top k Largest Number](https://www.lintcode.com/problem/top-k-largest-numbers/)  

## Tags
Hash & Heap (Data Structure)