# 75. Find Peak Element

## Description

There is an integer array which has the following features:

* The numbers in adjacent positions are different.
* A[0] < A[1] && A[A.length - 2] > A[A.length - 1].

We define a position P is a peak if:

* A[P] > A[P-1] && A[P] > A[P+1]

Find a peak element in this array. Return the index of the peak.
```
* It's guaranteed the array has at least one peak.
* The array may contain multiple peeks, find any of them.
* The array has at least 3 numbers in it.
```
**Notice**  
There can be duplicate elements in the array, and we can return any of the indices with same value.

**Example**
Given [1, 2, 1, 3, 4, 5, 7, 6]

Return index 1 (which is number 2) or 6 (which is number 7)

**Challenge**  
Time complexity O(logN)

## Link
[lintcode](https://www.lintcode.com/problem/find-peak-element/)

## Method
* Binary Search
  * key point : use the condition A[mid-1] < A[mid] > A[mid+1]

## Solution
1.1 Binary Search
~~~
class Solution {
public:
    /*
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int>& A) {
        // write your code here
        // peak element: A[k] > A[k-1] && A[k] > A[k+1]
        
        int start = 0, end = A.size() -1;
        
        if (A.size() < 3) {
            return -1;
        }
        
        // actually "start + 1 < end" garanteed at least 3 elements
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            
            // find one peak, return
            if (A[mid] > A[mid -1] && A[mid] > A[mid + 1]) {
                return mid;
            }
            else if (A[mid] < A[mid +1]) {
                start = mid;
            }
            else {
                end = mid;
            }
        }
        
        // not found
        return -1;
        
    }
};    
~~~
## Similar problems
[Find Peak Element II](https://www.lintcode.com/problem/find-peak-element-ii/)  
[Maximum Number in Moutain Sequence](https://www.lintcode.com/problem/maximum-number-in-mountain-sequence/)

## Tags
Binary Search