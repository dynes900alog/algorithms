# 159. Find Minimum in Rotated Sorted Array

## Description

Suppose a sorted array is rotated at some pivot unknown to you beforehand.  
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
```
You may assume no duplicate exists in the array.
```

**Example**
Given [4, 5, 6, 7, 0, 1, 2] return 0

## Link
[lintcode](https://www.lintcode.com/problem/find-minimum-in-rotated-sorted-array/)

## Method
* Binary Search
  * key point : find the pivot in 3 cases: not rotated (ascending), fully rotated (descending), normal rotated (half/half). All can be solved by comparing nums[mid] : nums[end]

  * 可以根据A[mid]和A[end]来判断右半数组是否sorted：  
原数组：0 1 2 4 5 6 7  
情况1：  6 7 0 1 2 4 5   
情况2：  2 4 5 6 7 0 1  
(1) A[mid] < A[end]：A[mid : end] sorted => min不在A[mid+1 : end]中
搜索A[start : mid]  
(2) A[mid] > A[end]：A[start : mid] sorted且又因为该情况下A[end]<A[start] => min不在A[start : mid]中, 搜索A[mid+1 : end]  
(3) base case：  
    * a. start =  end，必然A[start]为min，为搜寻结束条件。
    * b. start + 1 = end，此时A[mid] =  A[start]，而min = min(A[mid], A[end])。而这个条件可以合并到(1)和(2)中。

## Solution
1.1 Binary Search
~~~
class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        // write your code here
        int size = nums.size();
        
        if (size <= 0) {
            return -1;
        }
        
        int start = 0, end = size - 1;
        int target = nums[end];
        
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            
            if (nums[mid] < target) {
                end = mid;    
            }
            
            else {
                start = mid;
            }
        }
        
        return min(nums[start], nums[end]);
    }
};
~~~
## Similar problems
[Find Minimum in Rotated Sorted Array II](https://www.lintcode.com/problem/find-minimum-in-rotated-sorted-array-ii/)  
[Search in Rotated Sorted Array II](https://www.lintcode.com/problem/search-in-rotated-sorted-array-ii/)

## Tags
Binary Search