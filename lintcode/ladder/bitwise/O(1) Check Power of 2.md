# 142. O(1) Check Power of 2

## Description

Using O(1) time to check whether an integer n is a power of 2.

```
O(1) 时间复杂度
```
**Example**
```
For n=4, return true;
For n=5, return false;
```
**Challenge**  
O(1) time

## Link
[lintcode](https://www.lintcode.com/problem/o1-check-power-of-2)

## Method
* Bit manipulate
  * key point : n & (n - 1) to dermine power of 2

## Solution
1.1 Bit manipulate
~~~
class Solution {
public:
    /**
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        // write your code here
        return ((n > 0) && !(n & (n-1)));
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