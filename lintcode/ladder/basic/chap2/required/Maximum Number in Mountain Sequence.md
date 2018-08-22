# 585. Maximum Number in Mountain Sequence

## Description

Given a mountain sequence of n integers which increase firstly and then decrease, find the mountain top.

**Example**
Given nums = [1, 2, 4, 8, 6, 3] return 8
Given nums = [10, 9, 8, 7], return 10

## Link
[lintcode](https://www.lintcode.com/problem/maximum-number-in-mountain-sequence/)

## Method
* Binary Search
  * key point : use the condition A[mid-1] < A[mid] > A[mid+1]

## Solution
1.1 Binary Search
~~~
class Solution {
public:
    /**
     * @param nums: a mountain sequence which increase firstly and then decrease
     * @return: then mountain top
     */
    int mountainSequence(vector<int> &nums) {
        // write your code here
        int size = nums.size();
        if (size <= 0) {
            return -1;
        }
        
        int start = 0, end = size - 1;
        
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            
            // check if it's the peak
            if (nums[mid] > nums[mid -1] && nums[mid] > nums[mid + 1]) {
                return nums[mid];
            }
            if (nums[mid] > nums[mid + 1]) {
                end = mid;
            }
            else {
                start = mid;
            }
        }
        
        if (nums[start] > nums[end]) {
            return nums[start];
        }
        
        return nums[end];
    }
};
~~~
## Similar problems
[Find Peak Element](https://www.lintcode.com/problem/find-peak-element/)  

## Tags
Binary Search