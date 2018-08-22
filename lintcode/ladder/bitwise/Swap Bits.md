# 236. Swap Bits

## Description

Write a program to swap odd and even bits in an integer with as few instructions as possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on).

**Example**
```
5 = (101)2 => (1010)2 = 10
```
## Link
[lintcode](https://www.lintcode.com/problem/swap-bits/)

## Method
* Hash Table
  * key point : Hash Table to save <value, count>

## Solution
1.1 Hash Table
~~~
class Solution {
public:
    /*
     * @param x: An integer
     * @return: An integer
     */
    int swapOddEvenBits(int x) {
        // write your code here
        return (((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1));
    }
};
~~~
## Similar problems
[Rotate Bits - Left](https://www.lintcode.com/problem/rotate-bits-left/)  
[Swap Without Extra Variable Only C](https://www.lintcode.com/problem/swap-without-extra-variable-only-c/)   
[Binary Number with Alternating Bits](https://www.lintcode.com/problem/binary-number-with-alternating-bits/)   
[Flip Bits](https://lintcode.com/problem/flip-bits/)  
[Next Sparse Number](https://www.lintcode.com/problem/next-sparse-number/)  

## Tags
Bit Manipulate