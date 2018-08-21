# 28. Search a 2D Matrix

## Description

Write an efficient algorithm that searches for a value in an m x n matrix.

This matrix has the following properties:

* Integers in each row are sorted from left to right.
* The first integer of each row is greater than the last integer of the previous row.

**Notice**  
There can be duplicate elements in the array, and we can return any of the indices with same value.

**Example**
Consider the following matrix:
```
[
    [1, 3, 5, 7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
]
```
Given target = 3, return true.

**Challenge**  
O(log(n) + log(m)) time

## Link
[lintcode](https://www.lintcode.com/problem/search-a-2d-matrix/)

## Method
* Binary Search
  * key point : convert the coordinates of 2D from 1D

## Solution
1.1 Binary Search
~~~
class Solution {
public:
    /**
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        // write your code here
        int row = matrix.size();
        
        if ( row <= 0) {
            return false;
        }
        
        int col = matrix[0].size();
        
        if (col <= 0) {
            return false;
        }

        int start = 0, end = row * col - 1;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int x = mid / col;
            int y = mid % col;
            
            if (matrix[x][y] == target) {
                return true;
            }
            else if (matrix[x][y] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        
        return false;
    }
};
~~~
## Similar problems
[Search in Rotated Sorted Array](https://www.lintcode.com/problem/search-in-rotated-sorted-array/)
[Search a 2D Matrix II](https://www.lintcode.com/problem/search-a-2d-matrix-ii/)

## Tags
Binary Search