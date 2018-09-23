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
  * key point : state machine of one, two, three of "1" occurance times

## Solution
1.1 Bit manipulate
~~~
class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumberII(vector<int> &A) {
        // write your code here
        // Idea 1: use hash table to save all numbers' occurrance. Space O(n)
        return solution4(A);
    }
    
    // Idea 2: save the occurance of each 32 bits and the result is the occurance % 3
    int solution2(vector<int> &A) {
        int result = 0;
        for(int i = 0; i < 32; i++) {
            int sum = 0;
            for(int j = 0; j < A.size(); j++) {
                sum += (A[j] >> i) & 1;
            }
            sum = sum % 3;
            result |= sum << i;
        }
        
        return result;
    }
        return one;
    // Idea 3: one, two, three to record the occurance times 
    int solution3(vector<int> &A) {
        int one = 0, two = 0;
        for(int i = 0; i < A.size(); i++) {
            two |= (one & A[i]);
            one ^= A[i];
            int three = one & two;
            one &= ~three;
            two &= ~three;
        }
        
        return one;
    }
    
    
    /*利用位运算
     ones twos 分别表示出现一次和出现两次的即时结果
    遍历A
    对 ones操作， ones = ones ^ A[i] & (~tows)意思是把A[i] 计入到出现一次的情况里，但是有可能这个数已经出现过两次，所以要排除两次情况

    对 twos操作， twos = twos ^ A[i] & (~ones) 把A[i] 计入到两次情况，如果第三次出现了，自然消掉了，如果第二次出现，那么就计入，如果是第一次出现，不计入，这个过程通过和ones的非相交来控制

    */
    int solution4(vector<int> &A) {
        int one = 0, two = 0;
        for(int i = 0; i < A.size(); i++) {
            one = (one ^ A[i]) & (~two);
            two = (two ^ A[i]) & (~one);
        }
        
        return one;
    }
    
    /* Solution5: https://leetcode.com/problems/single-number-ii/discuss/43296/An-General-Way-to-Handle-All-this-sort-of-questions.
        "truth table" - https://blog.csdn.net/yutianzuijin/article/details/50597413
    */
};
~~~
## Similar problems
[Single Number](https://www.lintcode.com/problem/single-number/)  
[Single Number II](https://www.lintcode.com/problem/single-number-ii/)  
[Single Number III](https://www.lintcode.com/problem/single-number-iii/)   


## Tags  
Bit Manipulate