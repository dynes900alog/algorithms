# 144. Interleaving Positive and Negative Numbers

## Description

Given an array with positive and negative integers. Re-range it to interleaving with positive and negative integers.
```
You are not necessary to keep the original order of positive integers or negative integers.
```

**Example**
```
Given [-1, -2, -3, 4, 5, 6], after re-range, it will be [-1, 5, -2, 4, -3, 6] or any other reasonable answer.
```
**Challenge**  
Do it in-place and without extra memory.

## Link
[lintcode](https://www.lintcode.com/problem/interleaving-positive-and-negative-numbers/)

## Method
* Two Pointers: O(n) move forward by +2 steps by each move
  * key point : Determine the first position of return is positive or negative
## Solution
1.1 Two Pointers
~~~
class Solution {
public:
    /*
     * @param A: An integer array.
     * @return: nothing
     */
    void rerange(vector<int> &A) {
        // write your code here
        int length = A.size();

        // determine the final first number in array is positive or negative
        int posCnt = 0, negCnt = 0;
        for(int i = 0; i < length; i++) {
            if (A[i] > 0) {
                posCnt++;
            }
            else {
                negCnt++;
            }
        }
        
        int posIndex = 1;
        int negIndex = 0;
        
        if (posCnt > negCnt) {
            posIndex = 0;
            negIndex = 1;
        }
        
        // ineterleaving by partition: posIndex/negIndex move forward together by 2 steps
        while (posIndex < length && negIndex < length) {
            while(posIndex < length && A[posIndex] > 0) {
                posIndex += 2;
            }
            
            while(negIndex < length && A[negIndex] < 0) {
                negIndex += 2;
            }
            
            if (posIndex < length && negIndex < length) {
                swap(A[posIndex], A[negIndex]);
                posIndex += 2;
                negIndex += 2;
            }
        }

        return;
    }
};
~~~
## Similar problems
[Partition Array](https://www.lintcode.com/problem/partition-array)  

## Tags
Two Pointers  