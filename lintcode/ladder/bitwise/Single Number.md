# 82. Single Number

## Description

Given 2*n + 1 numbers, every numbers occurs twice except one, find it.

**Example**
```
Given [1,2,2,1,3,4,3], return 4
```
**Challenge**  
One-pass, constant extra space.

## Link
[lintcode](https://www.lintcode.com/problem/single-number/)

## Method
* Bit manipulate
  * key point : A XOR A = 0

## Solution
1.1 Bit manipulate
~~~
class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumber(vector<int> &A) {
        // write your code here
        int size = A.size();
        int result = 0;
        for(int i = 0; i < size; i++) {
            result ^= A[i];
        }
        
        return result;
    }
};
~~~
## Similar problems
[Single Number II](https://www.lintcode.com/problem/single-number-ii/)  
[Single Number III](https://www.lintcode.com/problem/single-number-iii/)   

## Tags  
Bit Manipulate