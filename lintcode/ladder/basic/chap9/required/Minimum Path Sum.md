# 110. Minimum Path Sum

## Description
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
```
You can only move either down or right at any point in time.
```


## Link
[lintcode](https://www.lintcode.com/problem/minimum-path-sum/)

## Method
* DP - Bottom Up

## Solution
1.1 DP 
~~~
class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int>> &grid) {
        // write your code here
        int row = grid.size();
        int col = grid[0].size();
        if (row <= 0 || col <= 0) {
            return 0;
        }
        
        // meaning: state dp[x][y]: minimum path sum from (0,0) to (x,y) 
        vector<vector<int>> dp(row, vector<int>(col, INT_MAX));
        dp[0][0] = grid[0][0];
        
        // initialize first row and first colum
        for(int i = 1; i < col; i++) {
            dp[0][i] = dp[0][i -1] + grid[0][i];
        }
        for(int i = 1; i < row; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        
        // dp: bottom 
        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j];
            }
        }
        
        return dp[row-1][col-1];
    }
};
~~~

## Similar problems
[Triangle](https://www.lintcode.com/problem/triangle/)  

## Tags
Dynamic Programming 坐标型