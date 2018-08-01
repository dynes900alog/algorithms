# 608. Two Sum II - Input array is sorted

## Description

Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
```
You may assume that each input would have exactly one solution.
```
**Example**
```
Given nums = [2, 7, 11, 15], target = 9
return [1, 2]
```

## Link
[lintcode](https://lintcode.com/problem/two-sum-input-array-is-sorted/)

## Method
* Two pointers (O(n), if use binary search will be O(nlongn))
  
## Solution
1.1 Two Pointers
~~~
class Solution {
public:
    /**
     * @param nums: an array of Integer
     * @param target: target = nums[index1] + nums[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        vector<int> result;
        
        int i = 0, j = nums.size() - 1;
        
        while(i < j) {
            int sum = nums[i] + nums[j];
            if (sum == target) {
                result.push_back(i + 1);
                result.push_back(j + 1);
                return result;
            }
            else if (sum < target) {
                i++;
            }
            else {
                j--;
            }
        }
        
        result.push_back(-1);
        result.push_back(-1);
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