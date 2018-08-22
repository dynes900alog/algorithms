# 4. Ugly Number II

## Description

Ugly number is a number that only have factors 2, 3 and 5.

Design an algorithm to find the nth ugly number. The first 10 ugly numbers are 1, 2, 3, 4, 5, 6, 8, 9, 10, 12...
```
Note that 1 is typically treated as an ugly number.
```
## Link
[lintcode](https://www.lintcode.com/problem/ugly-number-ii/)

## Method
* Min Heap (priority_quue) + Hash Set
  * Heap to keep adding the numbers of x*2, x*3, X*5 and pop up one number till N, 
* Only use Min heap 
  * Each round pop-up all equal elments 

## Solution
1.1 Doubly Linked List + Hash
~~~
class Solution {
public:
    /**
     * @param n: An integer
     * @return: the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        return uglyNumberPqOnly(n);
        

        // The following is the sultion of Min Heap + Hash Set
        vector<int> magic = {2, 3, 5};
        
        // By default, C++ priority_queue is maxheap, set to min heap 
        priority_queue<long, vector<long>, std::greater<long>> q;
        q.push(1);
        unordered_set<long> set;
        
        long result = 1;
        for(int i = 0; i < n; i++) {
            result = q.top();
            q.pop();
            for(int j = 0; j < magic.size(); j++) {
                long next = result * magic[j];
                if (set.find(next) == set.end()) {
                    q.push(next);
                    set.insert(next);
                }
            }
        }
        
        return result;        
    }
    
    int uglyNumberPqOnly(int n) {
        vector<int> magic = {2, 3, 5};
        
        // By default, C++ priority_queue is maxheap, set to min heap 
        priority_queue<long, vector<long>, std::greater<long>> q;
        q.push(1);

        long result = 1;
        for(int i = 0; i < n; i++) {
            result = q.top();
            for(int j = 0; j < magic.size(); j++) {
                long next = result * magic[j];
                q.push(next);
            }
            // pop up all equal elments of min
            while(q.top() == result) {
                q.pop();
            }
        }
        
        return result;        
    }
};
~~~

## Similar problems
[Consistent Hashing](https://www.lintcode.com/problem/consistent-hashing/)  
[LFU Cache (Least Frequently Used) ](https://www.lintcode.com/problem/lfu-cache/)  

## Tags
Hash & Heap (Data Structure)