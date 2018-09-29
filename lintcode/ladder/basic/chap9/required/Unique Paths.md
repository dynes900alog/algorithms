# 114. Unique Paths

## Description
A robot is located at the top-left corner of a m x n grid.
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid.
How many possible unique paths are there?
···
m and n will be at most 100.
···

**Example**  
Given m = 3 and n = 3, return 6.
Given m = 4 and n = 5, return 35.

## Link
[lintcode](https://www.lintcode.com/problem/unique-paths/)

## Method
* DP - Bottom Up

## Solution
1.1 DP 
~~~
class Solution {
public:
    /**
     * @param m: positive integer (1 <= m <= 100)
     * @param n: positive integer (1 <= n <= 100)
     * @return: An integer
     */
    int uniquePaths(int m, int n) {
        // write your code here
        // define the state:
        // dp[x][y]: unique paths from (0,0) to (x,y)
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        
        // initialization: row 0 and col 0 
        for(int i = 1; i < n; i++) {
            dp[0][i] = dp[0][i -1];
        }
        for(int i = 1; i < m; i++) {
            dp[i][0] = dp[i-1][0];
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};
~~~

1.2 DP  
(Same as 1.1 but with intialization inside the loop)
~~~
class Solution {
public:
    /**
     * @param m: positive integer (1 <= m <= 100)
     * @param n: positive integer (1 <= n <= 100)
     * @return: An integer
     */
    int uniquePaths(int m, int n) {
        // write your code here
        vector<vector<int>> dp(m, vector<int>(n,0));
        
        int i, j;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                }
                else if (i == 0) {
                    dp[i][j] = dp[i][j-1];
                }
                else if (j == 0) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};
~~~

## Similar problems
[Unique Paths III](https://www.lintcode.com/problem/unique-paths-iii/)  

## Tags
Dynamic Programming 坐标型