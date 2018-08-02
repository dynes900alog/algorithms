# 587. Two Sum - Unique Pairs

## Description

Given an array of integers, find how many unique pairs in the array such that their sum is equal to a specific target number. Please return the number of pairs.

**Example**
```
Given nums = [1,1,2,45,46,46], target = 47 return 2

1 + 46 = 47 2 + 45 = 47
```

**Challenge**  
Either of the following solutions are acceptable:

* O(n) Space, O(nlogn) Time
* O(n) Space, O(n) Time

## Link
[lintcode](http://www.lintcode.com/en/problem/two-sum-unique-pairs/)

## Method
* Hash Table
  * key point : Hash Table to save <value, count>

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
    int twoSum6(vector<int> &nums, int target) {
        // Write your code here
        if (nums.size() == 0) {
            return 0;
        }
 
        sort(nums.begin(), nums.end());
        
        int i = 0, j = nums.size() - 1;

        int result = 0;
        while(i < j) {
            int sum = nums[i] + nums[j];
            if (sum == target) {
                result++;
                i++; j--;
                // remove duplicated elements
                while(nums[i] == nums[i-1] && i < j) {
                    i++;
                }  
                while(nums[j] == nums[j +1] && i < j) {
                    j--;
                }
            }
            else if (sum < target) {
                i++;
            }
            else {
                j--;
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