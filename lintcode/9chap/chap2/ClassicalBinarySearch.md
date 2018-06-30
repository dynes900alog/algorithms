# 457. Classical Binary Search

## Description

Find any position of a target number in a sorted array. Return -1 if target does not exist.


Example
Given [1, 2, 2, 4, 5, 5].
For target = 2, return 1 or 2.
For target = 5, return 4 or 5.
For target = 6, return -1.

## Link
[lintcode](https://www.lintcode.com/submission/14120258/)

## Method
1. binary search template: start, end, while(start +1 < end), checking inside and outside while loop
2. checking inside while loop: ==, <, >, without mid++/mid--
3. outside checking: start, end

Key point:  start + 1 < end; checking inside/outside, at the end, check start/end

## Solution
1.1

class Solution {

public:

    /*
    
     * @param nums: An integer array sorted in ascending order
     
     * @param target: An integer
     
     * @return: An integer
     
     */
     
    int findPosition(vector<int> &nums, int target) {
        // write your code here
        if (nums.size() == 0) {
            return -1;
        }
        
        // directly use binary search template
        int start = 0;
        int end = nums.size() - 1;

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid]  == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                end = mid;
            } else {
                start = mid;
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


## Similar problems
x

## Tags
Binary Search
