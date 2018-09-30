# 115. Unique Paths II

## Description
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.
```
m and n will be at most 100.
```

**Example**  
For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.
```
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
```
The total number of unique paths is 2.

## Link
[lintcode](https://www.lintcode.com/problem/unique-paths-ii/)

## Method
* DP - Bottom Up  
  * state: dp[x][y]从起点到x,y的路径数
  * function: (研究倒数第一部) dp[x][y] = dp[x-1][y] + dp[x][y-1]
  * initialize: dp[0][i] = 1, dp[i][0] = 1
  * answer dp[n-1][m-1] 

## Solution
1.1 DP 
~~~
class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        // write your code here
        if (obstacleGrid.size() <= 0) {
            return 0;
        }
        
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));

        // initialize row 0 and col 0: if there is obstacle, the following cells in the same row/col are 0        
        dp[0][0] = 1;
        for(int i = 0; i < col; i++) {
            if (obstacleGrid[0][i] == 1) {
                break;
            }
            dp[0][i] = 1;    
        }
        for(int i = 0; i < row; i++) {
            if (obstacleGrid[i][0] == 1) {
                break;
            }
            dp[i][0] = 1;    
        }

        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        /* Can be compacted as the following code:
        for (int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                // obstacle, set to 0 (no ways to reach)
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = 0;
                    if (i==0 && j==0) {
                        dp[i][j] = 1;
                    }
                    if (j != 0) {
                        dp[i][j] += dp[i][j-1];
                    }
                    if (i != 0) {
                        dp[i][j] += dp[i -1][j];
                    }
                }
            }
        }
        */


        return dp[row-1][col-1];
    }
};
~~~

1.2 DFS with memorization  
~~~
// 记忆化搜索
// 九章硅谷求职算法集训营版本
public class Solution {
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
     
    int[][] f;
    int[][] A;
    int m;
    int n;
    
    void calc(int i, int j) {
        if (f[i][j] != -1) {
            return;
        }
        
        if (A[i][j] == 1) {
            f[i][j] = 0;
            return;
        }
        
        if (i == 0 && j == 0) {
            f[i][j] = 1;
            return;
        }
        
        f[i][j] = 0;
        if (i > 0) {
            calc(i - 1, j);
            f[i][j] += f[i - 1][j];
        }
        
        if (j > 0) {
            calc(i, j - 1);
            f[i][j] += f[i][j - 1];
        }
    }
    
    public int uniquePathsWithObstacles(int[][] AA) {
        A = AA;
        m = A.length;
        if (m == 0) {
            return 0;
        }
        
        n = A[0].length;
        if (n == 0) {
            return 0;
        }
        
        int i, j;
        f = new int[m][n];
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                f[i][j] = -1;
            }
        }
    
        calc(m - 1, n - 1);
        return f[m - 1][n - 1];
    }
}
~~~

## Similar problems
[Unique Paths](https://www.lintcode.com/problem/unique-paths/)  
[Unique Paths III](https://www.lintcode.com/problem/unique-paths-iii/)  

## Tags
Dynamic Programming 坐标型