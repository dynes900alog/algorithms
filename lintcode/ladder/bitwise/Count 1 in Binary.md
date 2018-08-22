# 179. Update Bits

## Description
Count how many 1 in binary representation of a 32-bit integer.

**Example**
```
Given 32, return 1
Given 5, return 2
Given 1023, return 9
```
**Challenge**  
If the integer is n bits with m 1 bits. Can you do it in O(m) time?

## Link
[lintcode](https://www.lintcode.com/problem/count-1-in-binary/)

## Method
* Bit manipulate
  * key point : "n & (n-1)" is used to strip off the most left 1

## Solution
1.1 Bit manipulate
~~~
class Solution {
public:
    /*
     * @param num: An integer
     * @return: An integer
     */
    int countOnes(int num) {
        // write your code here
        int count = 0;
        while(num) {
            num = num & (num-1);
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