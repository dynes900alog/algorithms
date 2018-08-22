# 179. Update Bits

## Description

Given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method to set all bits between i and j in N equal to M (e g , M becomes a substring of N located at i and starting at j)
```
In the function, the numbers N and M will given in decimal, you should also return a decimal number.
```
**Clarification**  
You can assume that the bits j through i have enough space to fit all of M. That is, if M=10011， you can assume that there are at least 5 bits between j and i. You would not, for example, have j=3 and i=2, because M could not fully fit between bit 3 and bit 2.

**Example**
```
Given N=(10000000000)2, M=(10101)2, i=2, j=6

return N=(10001010100)2
```
**Challenge**  
Minimum number of operations?

## Link
[lintcode](https://www.lintcode.com/problem/update-bits/)

## Method
* Bit manipulate
  * key point : how to generate mask bits from i ->j ? mask = (1 << (j+1)) - (1 << i)

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
[Rotate Bits - Left](https://www.lintcode.com/problem/rotate-bits-left/)  
[Swap Without Extra Variable Only C](https://www.lintcode.com/problem/swap-without-extra-variable-only-c/)   
[Binary Number with Alternating Bits](https://www.lintcode.com/problem/binary-number-with-alternating-bits/)   
[Flip Bits](https://lintcode.com/problem/flip-bits/)  
[Next Sparse Number](https://www.lintcode.com/problem/next-sparse-number/)  
[Binary Representation](https://www.lintcode.com/problem/binary-representation/)

## Tags  
Bit Manipulate