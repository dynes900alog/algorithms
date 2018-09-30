# 117. Jump Game II

## Description
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

**Example**  
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

## Link
[lintcode](https://www.lintcode.com/problem/jump-game-ii/)

## Method
* DP - Time Complexity is O(n^2)  
  * state: dp[x] - minimum steps from 0 -> x
  * function (Top Down): dp[x] = min(dp[y] + 1), when "dp[y] == true && y + A[y] >= x" for any y:[0, x)
  * initialize: dp[0] = 0
  * answer dp[size-1] 

* Greedy
## Solution
1.1 DP - Top Down
~~~
class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: An integer
     */
    int jump(vector<int> &A) {
        // write your code here
        int size = A.size();
        
        // dp[i]: minimum steps from 0 -> i
        vector<int> dp(size, 0);
        dp[0] = 0;
        
        for(int i = 1; i < size; i++) {
            dp[i] = INT_MAX;
            for(int k = 0; k < i; k++) {
                if((dp[k] != INT_MAX) && ((k + A[k]) >= i)) {
                    dp[i] = min(dp[i], dp[k]+1);
                }
            }
        }

        return dp[size-1];
    }
};
~~~

## Similar problems
[Jump Game](https://www.lintcode.com/problem/jump-game/)  
[Rogue Knight Sven](https://www.lintcode.com/problem/rogue-knight-sven/)  

## Tags
Dynamic Programming 坐标型  
Greedy
