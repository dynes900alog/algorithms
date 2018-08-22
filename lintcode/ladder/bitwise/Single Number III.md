# 84. Single Number III

## Description

Given 2*n + 2 numbers, every numbers occurs twice except two, find them.

**Example**
```
Given [1,2,2,3,4,4,5,3] return 1 and 5
```
**Challenge**  
O(n) time, O(1) extra space.

## Link
[lintcode](https://www.lintcode.com/problem/single-number-iii/)

## Method
* Bit manipulate
  * key point : Support A and B are the two numbers occurs only once. XOR to get diff of A and B, and key is how to separte the whole array into 2 groups, where one group contains A and the other contains B.

## Solution
1.1 Bit manipulate
~~~
class Solution {
public:
    /*
     * @param A: An integer array
     * @return: An integer array
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        // XOR to get "diff = x^y", from diff we can know the start bits from right-most where x diff from y
        // and we can seperate all array into two parts: one with x and the other with y
        int size = A.size();
        vector<int> result(2, 0);
        int diff = 0;
        for(int i = 0; i < size; i++) {
            // dff = x^y
            diff ^= A[i];
        }
        
        // get the lowest 1-bit position in diff where x diffs from y: note the trick here diff & (-diff)
        diff = diff & (-diff);
        
        for(int i = 0; i < size; i++) {
            if (diff & A[i]) {
                result[0] ^= A[i];
            }
            else {
                result[1] ^= A[i];
            }
        }
        
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