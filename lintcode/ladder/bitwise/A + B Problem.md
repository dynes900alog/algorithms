# 1. A + B Problem

## Description

Write a function that add two numbers A and B.
```
There is no need to read data from standard input stream. Both parameters are given in function aplusb, you job is to calculate the sum and return it.
```
**Clarification**  
Are a and b both 32-bit integers?
* Yes.  

Can I use bit operation?

* Sure you can.

**Example**  

Given a=1 and b=2 return 3.

**Challenge**
Of course you can just return a + b to get accepted. But Can you challenge not do it like that?(You should not use + or any arithmetic operators.)

## Link
[lintcode](https://www.lintcode.com/problem/a-b-problem/)

## Method
* Bit Wise
  * key point : "(a ^ b)" : "a + b" without carry; "(a & b) << 1" : carry 

## Solution
1.1 Bitwise
~~~
class Solution {
public:
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: The sum of a and b 
     */
    int aplusb(int a, int b) {
        // write your code here
        // Note: a + b = (a ^ b) + ((a & b) << 1) (carry)
        while (b != 0) {
            int carry = a & b;
            a = a  ^ b;
            b = carry << 1;
        }
        
        return a;
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