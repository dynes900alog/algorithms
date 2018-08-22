# 181. Flip Bits

## Description

Determine the number of bits required to flip if you want to convert integer n to integer m.
```
Both n and m are 32-bit integers.
```

**Example**
```
Given n = 31 (11111), m = 14 (01110), return 2.
```
**Challenge**  
How many ways to do it?

## Link
[lintcode](https://www.lintcode.com/problem/flip-bits/)

## Method
* Bit manipulate
  * key point : XOR and "n&(n-1)" to get count of 1-bit

## Solution
1.1 Bit manipulate
~~~
class Solution {
public:
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        int diff = a ^ b;
        int count = 0;
        while(diff) {
            diff = diff & (diff - 1);
            count++;
        }
        
        return count;
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