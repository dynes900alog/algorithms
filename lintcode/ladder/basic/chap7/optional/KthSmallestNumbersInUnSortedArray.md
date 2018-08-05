# 461. Kth Smallest Numbers In Unsorted Array

## Description

Find the kth smallest numbers in an unsorted integer array.

**Example**
```
Given [3, 4, 1, 2, 5], k = 3, the 3rd smallest numbers are [1, 2, 3].
```
## Link
[lintcode](https://www.lintcode.com/problem/kth-largest-element/)

Challenge 
An O(nlogn) algorithm is acceptable, if you can do it in O(n), that would be great.

## Method
* Two Pointers O(nlongn)
Same way as Find Kth largest

## Solution
1.1 Two Pointers
~~~
class Solution {
public:
    /*
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthSmallest(int k, vector<int> &nums) {
        // write your code here
        if (nums.size() <= 0) {
            return 0;
        }
        if (n <= 0) {
            return 0;
        }
        
        // partion
        int start = 0, end = nums.size() - 1;

        // convert to the kth smallest number
        return helper(nums, start, end, k);
    }
    
    int helper(vector<int>  &nums, int start, int end, int k) {
        if (start == end) {
            return nums[start];
        }

        // partition as: [<= pivot, pivot position, >= pivot] 
        int position = partition(nums, start, end);
        if (position + 1 == k) {
            return nums[position];
        }
        else if ( position + 1 < k) {
            return helper(nums, position + 1, end);
        }
        else {
            return helper(nums, start, position - 1);
        }
    }
    
    // return index of pivot position: note how to parition
    int partition(vector<int> &nums, int start, int end) {
        int pivot = nums[start];
        int i = start, j = end;
        // partion into 3 parts, [ < pivot, = pivot, >=pivot]
        while(i < j) {
            while(i < j && nums[j] >= pivot) {
                j--;
            }
            nums[i] = nums[j];

            while(i < j && nums[i] <= pivot) {
                i++;
            }
            nums[j] = nums[i];
        }

        nums[i] = pivot;

        return i;
    }
};
~~~

## Similar problems
[Kth Largest Element](https://lintcode.com/problem/kth-largest-element/)  
[Kth Smallest Numbers in Unsorted Array](https://www.lintcode.com/problem/kth-smallest-numbers-in-unsorted-array/)  
[Kth Smallest Number in Sorted Matrix](https://www.lintcode.com/problem/kth-smallest-number-in-sorted-matrix/)

## Tags
Two Pointers  