# 14. First Position of Target

## Description

For a given sorted array (ascending order) and a target number, find the first index of this number in O(log n) time complexity.
If the target number does not exist in the array, return -1.

## Example
If the array is [1, 2, 3, 3, 4, 5, 10], for given target 3, return 2.

## Challenge
If the count of numbers is bigger than 2^32, can your code work properly?

## Link
[lintcode](https://lintcode.com/problem/first-position-of-target/)

## Method
* Binary Search

## Solution
1.1 Bianry Search (Template, without using template, be careful left/right choose based on mide and post processing)
~~~
class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &nums, int target) {
        // write your code here
        int size = nums.size();
        if (size == 0) {
            return -1;
        }
        
        int start = 0, end = size - 1;
        while (start + 1 < end) {
            int mid = start + (end - start)/2;
            // 3 cases
            if (nums[mid] == target) {
                // find first
                end = mid;
            }
            else if (nums[mid] < target) {
                start = mid;
            }
            else {
                end = mid;
            }
        }
        
        if (nums[start] == target) {
            return start;
        }
        
        if (nums[end] == target) {
            return end;
        }
        
        return -1;
    }
};
~~~

## Similar problems
[Last position of Target](https://www.lintcode.com/problem/last-position-of-target/)  

## Tags
Binary Search