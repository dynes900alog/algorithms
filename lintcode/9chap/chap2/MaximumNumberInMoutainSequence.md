# 585. Maxmum Number in Mountain Sequence

## Description

Given a mountain sequence of n integers which increase firstly and then decrease, find the mountain top.
Example
Given nums = [1, 2, 4, 8, 6, 3] return 8
Given nums = [10, 9, 8, 7], return 10

## Link
[lintcode](https://www.lintcode.com/en/problem/maximum-number-in-mountain-sequence/)

## Method
1. binary search, for mid postion, if mid is bigger than start, check if it's increasing or decreasing part:
 check nums[mid] > or < nums[mid+1] to determine if peak is on left or right side.
2. If mid is smaller than start, only one case that peak is in the left half part.

Key point: 利用nums[i]和nums[i+1]来比较得到是处于上升或下降区间
## Solution
1.1

class Solution {

public:

    /**

     * @param nums a mountain sequence which

      increase firstly and then decrease

     * @return then mountain top
     
     */

    int mountainSequence(vector<int>& nums) {
        // Write your code here
        if (nums.empty()) {
            return -1;
        }

        int start = 0;
        int end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > nums[start] {
                // the peak could be either sides of mid position
                // note here always "mid  < end" so mid + 1 is valid
                if (nums[mid] < nums[mid + 1]>) {
                    start = mid;
                }
                else {
                    end = mid;
                }
            }
            else {
                // the peak is on left side of mid
                end = mid;
            }

        }

        if (nums[start] > nums[end]) {
            return nums[start];
        }

        return nums[end];
    }
};


化简版本：

class Solution {

public:

    /**

     * @param nums a mountain sequence which increase firstly and then decrease

     * @return then mountain top

     */

    int mountainSequence(vector<int>& nums) {

        // Write your code here

        int start = 0, end = nums.size() - 1;

        while (start + 1 < end) {

            int mid = start + (end - start) / 2;

            if (nums[mid] < nums[mid + 1]) {

                start = mid + 1;

            }

            else {

                end = mid;

            }

        }

        

        return max(nums[start], nums[end]);

    }

};
## Similar problems
x

## Tags
Binary Search