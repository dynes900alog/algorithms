# 6. Merge Two Sorted Array

## Description
~~~
Merge two given sorted integer array A and B into a new sorted integer array.

~~~

**Example**
```
A=[1,2,3,4]

B=[2,4,5,6]

return [1,2,2,3,4,4,5,6]
```
**Challenge**

How can you optimize your algorithm if one array is very large and the other is very small?

## Link
[lintcode](https://www.lintcode.com/problem/merge-two-sorted-arrays/)

## Method
* Two Pointers

## Solution
1.1 
~~~
class Solution {
public:
    /**
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        int lenA = A.size();
        int lenB = B.size();
        vector<int> result;
        
        int i = 0;
        int j = 0;
        while(i < lenA && j < lenB) {
            if (A[i] <= B[j]) {
                result.push_back(A[i]);
                i++;
            }
            else {
                result.push_back(B[j]);
                j++;
            }
        }
        
        while (i < lenA) {
            result.push_back(A[i++]);
        }
        
        while (j < lenB) {
            result.push_back(B[j++]);
        }
        
        return result;
    }
};
~~~

## Similar problems
[Merge Two Sorted Lists](https://www.lintcode.com/problem/merge-two-sorted-lists/)  
[Merge Sorted Array](https://www.lintcode.com/problem/merge-sorted-array/)
## Tags
Array
