# 148. Sort Colors

## Description

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
```
You are not suppose to use the library's sort function for this problem.
You should do it in-place (sort numbers in the original array).
```
**Example**
```
Given [1, 0, 1, 2], sort it in-place to [0, 1, 1, 2].
```
**Challenge**  
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?

## Link
[lintcode](https://www.lintcode.com/problem/sort-colors/)

## Method
* Counting Sort 
* Partition twice: 1. partion into part1 (== 0) part2 (>0) 2. partion the part2 
* 3-way quick sort partion: 3 pointers( left, middle, right)
  * key point : the definitions of 3 pointers - left (left side has handled "0", not include left postion itself); middle (iterator); right (right side has handleded "2", not include right itself)

## Solution
1.1 Three Pointers
~~~
class Solution {
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */
    void sortColors(vector<int> &nums) {
        // write your code here
        int length = nums.size();
        // define: 
        // left - all the elements on the left side, but not include "left" have "0", which menas has been handled
        // right: all the elements on the right side of "right", but not include "right" have "2" (handled). and "right" itsel not handled yet
        int left = 0, i = 0, right = length -1;
        
        int pivot = 1;
        
        // Note i == right need to handle (nums[i] may == 0)
        while(i <= right) {
            if (nums[i] == pivot) {
                i++;
            }
            else if (nums[i] < pivot) {
                swap(nums[i], nums[left]);
                i++;
                left++;
            }
            else {
                swap(nums[i], nums[right]);
                right--;
            }
        }
        
        return;
    }
};
~~~
## Similar problems
[Partition Array II](https://lintcode.com/problem/two-sum/)  
[Sort Colors II](https://lintcode.com/problem/two-sum-input-array-is-sorted/)   
[Wiggle Sort](https://lintcode.com/problem/two-sum-less-than-or-equal-to-target/)  

## Tags
Two Pointers  