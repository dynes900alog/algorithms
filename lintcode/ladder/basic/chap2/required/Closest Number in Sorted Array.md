# 459. Closest Number in Sorted Array

## Description

Given a target number and an integer array A sorted in ascending order, find the index i in A such that A[i] is closest to the given target.

Return -1 if there is no element in the array.

**Notice**  
There can be duplicate elements in the array, and we can return any of the indices with same value.

**Example**
```
Given [1, 2, 3] and target = 2, return 1.
Given [1, 4, 6] and target = 3, return 1.
Given [1, 4, 6] and target = 5, return 1 or 2.
Given [1, 3, 3, 4] and target = 2, return 0 or 1 or 2.
```

**Challenge**  
O(logn) time complexity.

## Link
[lintcode](https://lintcode.com/problem/closest-number-in-sorted-array/)

## Method
* Binary Search
  * key point : 

## Solution
1.1 Binary Search
~~~
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int closestNumber(vector<int>& A, int target) {
        // write your code here
        unsigned int start = 1, end = A.size() - 1;
        
        while (start + 1  < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) {
                return mid;
            }
            else if (A[mid] < target) {
                start = mid;
            }
            else {
                end = mid;
            }
        }

        return (abs(A[start] - target) < abs(A[end] - target) ? start : end);        
    }
};
~~~
## Similar problems
[Closest Number in Sorted Array](https://www.lintcode.com/problem/closest-number-in-sorted-array/)

## Tags
Binary Search