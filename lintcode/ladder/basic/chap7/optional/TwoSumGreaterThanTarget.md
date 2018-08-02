# 443. Two Sum - Greater than target

## Description

Given an array of integers, find how many pairs in the array such that their sum is bigger than a specific target number. Please return the number of pairs.

**Example**
```
Given numbers = [2, 7, 11, 15], target = 24. Return 1. (11 + 15 is the only pair)

```

## Link
[lintcode](http://lintcode.com/en/problem/two-sum-greater-than-target/)

## Method
* Two Pointers
  * key point : quick calculating pairs after sorting

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
    int twoSum2(vector<int> &nums, int target) {
        // Write your code here
        if (nums.size() == 0) {
            return 0;
        }
 
        sort(nums.begin(), nums.end());

        int left = 0, right = nums.size() - 1;

        int result = 0;
        while(left < right) {
            int sum = nums[left] + nums[right];
            if (sum <= target) {
                result += right - left;
                right++; 
            }
            else {
                left++;
            }
        }

        return result;
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