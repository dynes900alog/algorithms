# 111. Climbing Stairs

## Description
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

**Example**  
```
Given an example n=3 , 1+1+1=2+1=1+2=3

return 3
```
## Link
[lintcode](https://www.lintcode.com/problem/climbing-stairs/)

## Method
* DP - Bottom Up  
  * state: dp[x] 从起点到x+1的路径数
  * function: (研究倒数第一部) dp[x] = dp[x-1] + dp[x-2]
  * initialize: dp[0] = 1, dp[1] = 2
  * answer dp[n-1] 

## Solution
1.1 DP 
~~~
class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        if (n <= 0) {
            return 0;
        }
        
        int dp[n];
        
        dp[0] = 1;
        dp[1] = 2;
        
        for(int i = 2; i < n; i++) {
            dp[i] = dp[i -2] + dp[i -1];
        }
        
        return dp[n -1];
    }
};
~~~

1.2 DP  
(Same as 1.1 but save space)
~~~
class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        if (n <= 1) {
            return n;
        }
        
        int dp[3];

        // initialize        
        dp[0] = 1;
        dp[1] = 2;

        for(int i = 2; i < n; i++) {
            dp[2] = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = dp[2];
        }

        // in case n = 2 so return dp[1]
        return dp[1];
    }
};
~~~

## Similar problems
[366. Fibonacci](https://www.lintcode.com/problem/fibonacci/)  
[392. House Robber](https://www.lintcode.com/problem/house-robber/)  

## Tags
Dynamic Programming 坐标型