# 462. Total Occurrence of Target

## Description

Given a target number and an integer array sorted in ascending order. Find the total number of occurrences of target in the array.


Example
Given [1, 3, 3, 4, 5] and target = 3, return 2.

Given [2, 2, 3, 4, 6] and target = 4, return 1.

Given [1, 2, 3, 4, 5] and target = 6, return 0.

## Link
[lintcode](http://www.lintcode.com/en/problem/total-occurrence-of-target/)

## Method
1. binary search to find first and last occurrence of target positions

Key point: 

## Solution
1.1

class Solution {

public:

    /**

     * @param nums a mountain sequence which

      increase firstly and then decrease

     * @return then mountain top
     
     */

    int totalOccurrence(vector<int>& A, int target) {
        // Write your code here
        if (A.empty()) {
            return -1;
        }
        int left, right;

        int start = 0, end = A.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] >= target) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (A[start] == target) {
            left = start;
        } else if (A[end] == target) {
            left = end;
        } else {
            return 0;
        }
 
        start = left;
        end = A.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] <= target) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (A[end] == target) {
            right = end;
        } else if (A[start] == target) {
            right = start;
        } else {    // shouldn't come to this branch
            return 0;
        }
        return right - left + 1;
    }
};

## Similar problems
x

## Tags
Binary Search