# 533. Two Sum - Closest to target

## Description

Given an array nums of n integers, find two integers in nums such that the sum is closest to a given number, target.

Return the difference between the sum of the two integers and the target.


**Example**
```
Given array nums = [-1, 2, 1, -4], and target = 4.

The minimum difference is 1. (4 - (2 + 1) = 1).

```
**Challenge**
Do it in O(nlongn) time complexity

## Link
[lintcode](https://lintcode.com/problem/two-sum-closest-to-target/)

## Method
* Two Pointers

## Solution
1.1 Hash Table
~~~
class Solution {
public:
    /**
     * @param nums an array of integer
     * @param target an integer
     * @return an integer
     */
    int twoSumClosest(vector<int> &nums, int target) {
        // Write your code here
        if (nums.size() == 0) {
            return 0;
        }
 
        sort(nums.begin(), nums.end());

        int left = 0, right = nums.size() - 1;

        int minDelta = INT_MAX;
        while(left < right) {
            int sum = nums[left] + nums[right];
            int minDelta = min(minDelta, abs(target -sum));
            if (sum < target) {
                left++; 
            }
            else {
                right--;
            }
        }

        return minDelta;
    }    
};
~~~
## Similar problems
[Two Sum](https://lintcode.com/problem/two-sum/)  
[Two Sum II - Input array is sorted](https://lintcode.com/problem/two-sum-input-array-is-sorted/)   
[Two Sum II - Less than or equal to target](https://lintcode.com/problem/two-sum-less-than-or-equal-to-target/)   
[Two Sum - Unique pairs](https://lintcode.com/problem/two-sum-unique-pairs/)  
[Two Sum - Closest to target](https://lintcode.com/problem/two-sum-closest-to-target/)  
[Two Sum - Difference equals to target](https://lintcode.com/problem/two-sum-difference-equals-to-target/)  
[Two Sum - Greater than target](https://lintcode.com/problem/two-sum-greater-than-target/)  
[Two Sum III- Data structure design](https://lintcode.com/problem/two-sum-data-structure-design/)  
[3Sum](https://lintcode.com/problem/3sum/)

## Tags
Two Pointers  