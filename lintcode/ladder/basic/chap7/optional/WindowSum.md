# 604. Window Sum

## Description
~~~
Given an array of n integer, and a moving window(size k), move the window at each iteration from the start of the array, find the sum of the element inside the window at each moving.

~~~

**Example**
```
For array [1,2,7,8,5], moving window size k = 3.
1 + 2 + 7 = 10
2 + 7 + 8 = 17
7 + 8 + 5 = 20
return [10,17,20]
```
## Link
[lintcode](https://www.lintcode.com/problem/window-sum/)

## Method
* PrefixSum  

## Solution
1.1 
~~~
class Solution {
public:
    /**
     * @param nums: a list of integers.
     * @param k: length of window.
     * @return: the sum of the element inside the window at each moving.
     */
    vector<int> winSum(vector<int> &nums, int k) {
        // write your code here
        vector<int> result;
        int size = nums.size();
        
        if (k < 0 || nums.size() < k) {
            return result;
        }

        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }

        result.push_back(sum);
        // two pointers "i" in window and "i -k" out window
        for(int i = k; i < size; i++) {
            sum = sum + nums[i] - nums[i -k];
            result.push_back(sum);
        }
        
        return result;
    }
};
~~~

## Similar problems
[Moving Average from Data Stream](https://www.lintcode.com/problem/moving-average-from-data-stream/)  

[Sliding Window Unique Elements Sum](https://www.lintcode.com/problem/sliding-window-unique-elements-sum/)  

## Tags
Linked List & Array   
Two Pointers
