# 64. Merge Sorted Array

## Description
~~~
Given two sorted integer arrays A and B, merge B into A as one sorted array.

You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
~~~

**Example**
```
A = [1, 2, 3, empty, empty], B = [4, 5]

After merge, A will be filled as [1, 2, 3, 4, 5]
```
**Challenge**

How can you optimize your algorithm if one array is very large and the other is very small?  
(insert sort by binary search to get insert postion of the small array elements)

## Link
[lintcode](https://www.lintcode.com/problem/merge-sorted-array/)

## Method
* Two Pointers

## Solution
1.1 
~~~
class Solution {
public:
    /*
     * @param A: sorted integer array A which has m elements, but size of A is m+n
     * @param m: An integer
     * @param B: sorted integer array B which has n elements
     * @param n: An integer
     * @return: nothing
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        int i = m - 1, j = n - 1, k = m + n -1;
        
        while(i >= 0 && j >= 0) {
            A[k--] = (A[i] > B[j]) ? A[i--] : B[j--];
        }
        
        while(i >= 0) {
            A[k--] = A[i--];
            k--;i--;
        }
        
        while(j >= 0) {
            A[k--] = B[j--];
        }
    }
};
~~~

## Similar problems
[Merge Two Sorted Arrays](https://www.lintcode.com/problem/merge-two-sorted-arrays/)  
## Tags
Array
