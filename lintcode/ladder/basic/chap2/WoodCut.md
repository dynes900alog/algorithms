# Wood Cut

## Description

Given a mountain sequence of n integers which increase firstly and then decrease, find the mountain top.
Example
Given nums = [1, 2, 4, 8, 6, 3] return 8
Given nums = [10, 9, 8, 7], return 10

## Link
[lintcode](https://www.lintcode.com/en/problem/maximum-number-in-mountain-sequence/)

## Method
1. binary search, try to limit top into mid<->rightMid, or leftMid<->mid
2. x

## Solution
1.1

class Solution {

public:

    /**

     * @param nums a mountain sequence which

      increase firstly and then decrease

     * @return then mountain top
     
     */

    // Version 1, mid, rightMid
    int mountainSequence(vector<int>& nums) {
        // Write your code here
        if (nums.empty()) {
            return -1;
        }
        int result = 0;
        int start = 0;
        int end = nums.size() - 1;
        while (start + 1 < end) {
            // mid tend to left
            int mid = start + (end - start) / 2;
            // rightMid tend to right
            // when mid = end - 1, rightMid = end
            int rightMid = end - (end - mid) / 2;
            // in the increasing part:  mid 1 2 3 rightMid
            if (nums[mid] < nums[rightMid]) {
                start = mid + 1;
            // in the decreasing part: mid 3 2 1 rightMid
            } else if (nums[mid] > nums[rightMid]) {
                end = rightMid -1;
            // equal part: mid 1 7 1 rightMid
            } else {
                start = mid;
                end = rightMid;
            }
        }
        result = max(nums[start], nums[end]);
        return result;
    }
    // ----------------------------------------------------------
    // Version 2, leftMid, mid
    int mountainSequence(vector<int>& nums) {
        if (nums.empty()) {
            return -1;
        }
        int result = 0;
        int start = 0;
        int end = nums.size() -1;
        while (start + 1 < end) {
            // mid tend to left
            int mid = start + (end - start) / 2;
            // leftMid tend to left
            // when mid = start + 1, leftMid = start
            int leftMid = start + (mid - start) / 2;
            // increasing part, leftMid 1 2 3 mid
            if (nums[leftMid] < nums[mid]) {
                start = leftMid + 1;
            // decreasing part, leftMid 3 2 1 mid
            } else if (nums[leftMid] > nums[mid]) {
                end = mid - 1;
            // equal part, top in the middle, leftMid 1 7 1 mid
            } else {
                start = leftMid;
                end = mid;
            }
        }
        result = max(nums[start], nums[end]);
        return result;
    }
};

## Similar problems
x

## Tags
Binary Search