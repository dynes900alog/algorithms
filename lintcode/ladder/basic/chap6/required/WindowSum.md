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
        
        int sum = 0;
        for(int i = 0; i < size; i++) {
            sum += nums[i];
            if (i < k -1) {
                continue;
            }
            if (i >= k) {
                sum = sum - nums[i -k];
            }
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
