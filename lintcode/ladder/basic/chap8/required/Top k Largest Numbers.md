# 544. Top k Largest Numbers

## Description

Given an integer array, find the top k largest numbers in it.

##Example##
Given [3,10,1000,-99,4,100] and k = 3.
Return [1000, 100, 10].
## Link
[lintcode](https://www.lintcode.com/problem/top-k-largest-numbers/)

## Method
* Min Heap 
  * Time complexity: O(nlogk)
  * Space: O(k)

## Solution
1.1 Doubly Linked List + Hash
~~~
// Time: O(nlogk) and Space: O(k)

class Solution {
public:
    /**
     * @param nums: an integer array
     * @param k: An integer
     * @return: the top k largest numbers in array
     */
    vector<int> topk(vector<int> &nums, int k) {
        // write your code here
        // Define Min Heap
        vector<int> result;
        priority_queue<int, vector<int>, std::greater<int>> pq;
        
        for(auto num : nums) {
            if (pq.size() < k) {
                pq.push(num);
            }
            else {
                int value = pq.top();
                if (num > value) {
                    pq.pop();
                    pq.push(num);
                }
            }
        }
        
        // retrieve all K elements
        while(!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};
~~~

## Similar problems
[Top k Largest Number II](https://www.lintcode.com/problem/top-k-largest-numbers-ii/)  

## Tags
Hash & Heap (Data Structure)