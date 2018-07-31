# 539. Move Zeroes

## Description

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
```
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
```

**Example**
```
Given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
```

**Challenge**  
Can you implement it in three different algorithms?

## Link
[lintcode](https://lintcode.com/problem/move-zeroes/)

## Method
* Two Pointers
  * key point : how to move & make the second pointer always point to "0" when the first pointer move forward?

## Solution
1.1 Two Pointers
~~~
class Solution {
public:
    /**
     * @param nums: an integer array
     * @return: nothing
     */
    void moveZeroes(vector<int> &nums) {
        // write your code here
        int size = nums.size();
        //i: the first postion for 0, j: the first position immediately after "i" and is not 0
        int i = 0, j = 0;
        while(j < size) {
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }
    }
};
~~~


## Similar problems
[Remove Element](https://lintcode.com/problem/remove-element/)  
## Tags
Two Pointers
