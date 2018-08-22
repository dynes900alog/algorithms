# 83. Single Number II

## Description

Given 3*n + 1 numbers, every numbers occurs triple times except one, find it.

**Example**
```
Given [1,1,2,3,3,3,2,2,4,1] return 4
```
**Challenge**  
One-pass, constant extra space.

## Link
[lintcode](https://www.lintcode.com/problem/single-number-ii/)

## Method
* Bit manipulate
  * key point : 

## Solution
1.1 Bit manipulate
~~~
class Solution {
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param i: A bit position
     * @param j: A bit position
     * @return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        // write your code here
        int mask = 0;
        // Note if j is 31, 1<<j out of range
        if (j < 31) {
            mask = ~((1 << (j+1)) - (1 << i));
        }
        else {
            mask = (1 << i) - 1;
        }

        // clear the content in n from i to j
        int result = n & mask;
        
        // set m in n
        result = result | (m << i);
        
        return result;
    }
};
~~~
## Similar problems
[Single Number](https://www.lintcode.com/problem/single-number/)  
[Single Number II](https://www.lintcode.com/problem/single-number-ii/)  
[Single Number III](https://www.lintcode.com/problem/single-number-iii/)   


## Tags  
Bit Manipulate