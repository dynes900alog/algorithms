# 109. Triangle

## Description
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
```
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
```

**Example**
Given the following triangle:
```
[
    [2],
    [3,4],
    [6,5,7],
    [4,1,8,3]
]
```
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

## Link
[lintcode](https://www.lintcode.com/problem/triangle/)

## Method
* Divide Conquer - triagnel has n rows, Time Complexity O(2^n), n is total rows (layers)
  
* Divide & Conquer + Memerize Search (DP) - O(n^2) each node accessed twice
  
* DP - Bottom Up

* DP - Top Down
## Solution
1.1 Divide & Conquer (Time out)
~~~
class Solution {
public:
    /**
     * @param triangle: a list of lists of integers
     * @return: An integer, minimum path sum
     */
    int minimumTotal(vector<vector<int>> &triangle) {
        // write your code here
        if (triangle.size() <= 0 || triangle[0].size() <= 0) {
            return 0;
        }
        
        row = triangle.size();
        col = triangle[row -1].size();
        
        // DFS, time complexity is O(2^n) if there is n rows : row 0 (1),  row 1 (2) , row 2 (4) , row 3 (8) ... row n-1 (2^(n-1)), this is becasue of a lot of repeated calculation
        return dfs(triangle, 0, 0);
    }
    
    // DFS: divide and conquer without memorization
    int dfs(vector<vector<int>> &triangle, int x, int y) {
        if (x >= row || y > x) {
            return 0;
        }
        
        // Divide & Conquer
        int left = dfs(triangle, x + 1, y);
        int right = dfs(triangle, x + 1, y + 1);
        
        // Merge
        return min(left, right) + triangle[x][y];
    }

 private:
    int row;
    int col;
};    
~~~

1.2 Divide Conquer + Memorization search
~~~
class Solution {
public:
    /**
     * @param triangle: a list of lists of integers
     * @return: An integer, minimum path sum
     */
    int minimumTotal(vector<vector<int>> &triangle) {
        // write your code here
        if (triangle.size() <= 0 || triangle[0].size() <= 0) {
            return 0;
        }
        
        row = triangle.size();
        col = triangle[row -1].size();
        hashtable = vector<vector<int>>(row, vector<int>(col, INT_MAX));
        
        // DFS, time complexity is O(2^n) if there is n rows : row 0 (1),  row 1 (2) , row 2 (4) , row 3 (8) ... row n-1 (2^(n-1)), this is becasue of a lot of repeated calculation
        return dfs(triangle, 0, 0);
    }
    
    // DFS: divide and conquer with memorization
    int dfs(vector<vector<int>> &triangle, int x, int y) {
        if (x >= row || y > x) {
            return 0;
        }
        
        // memorization (if not, time complexity is "O(2^n)" )
        if (hashtable[x][y] != INT_MAX) {
            return hashtable[x][y];
        }
        
        // Divide & Conquer
        int left = dfs(triangle, x + 1, y);
        int right = dfs(triangle, x + 1, y + 1);
        
        // Merge
        hashtable[x][y] = min(left, right) + triangle[x][y];

        return hashtable[x][y];
    }

 private:
    vector<vector<int>> hashtable;
    int row;
    int col;
};
~~~

1.3 DP - Top Down
~~~
class Solution {
public:
    /**
     * @param triangle: a list of lists of integers
     * @return: An integer, minimum path sum
     */
    int minimumTotal(vector<vector<int>> &triangle) {
        // write your code here
        if (triangle.size() <= 0 || triangle[0].size() <= 0) {
            return 0;
        }
        
        row = triangle.size();
        col = triangle[row -1].size();
        
        // DP: time complexity is O(n^2): each node calculate onece: 1 + 2 + 3 + ... + n
        return dpTopDown(triangle);
    }
    
    // DP: Top Down    
    int dpTopDown(vector<vector<int>> &triangle) {
        // Define of state dp[i][j]: the mininum path sum from position (i,j) to the last row
        vector<vector<int>> dp(row, vector<int>(col, INT_MAX));
        
        dp[0][0] = triangle[0][0];
        
        // Initialize 
        for(int i = 1; i < row; i++) {
            dp[i][0] = dp[i -1][0] + triangle[i][0];
            dp[i][i] = dp[i-1][i-1] + triangle[i][i];
        }
        
        // Bottom Up
        for(int i = 1; i < row; i++) {
            for(int j = 1; j < i; j++) {
                dp[i][j] = triangle[i][j] + min(dp[i-1][j -1], dp[i - 1][j]);
            }
        }
        
        // find the last row's minimum and return
        int ret = INT_MAX;
        
        for(int i = 0; i < row; i++) {
            ret = min(ret, dp[row -1][i]);
        }
        
        return ret;
    }

private:
    int row;
    int col;
};
~~~

1.4 DP - Bottom Up
~~~class Solution {
public:
    /**
     * @param triangle: a list of lists of integers
     * @return: An integer, minimum path sum
     */
    int minimumTotal(vector<vector<int>> &triangle) {
        // write your code here
        if (triangle.size() <= 0 || triangle[0].size() <= 0) {
            return 0;
        }
        
        row = triangle.size();
        col = triangle[row -1].size();
        
        // DP: time complexity is O(n^2): each node calculate onece: 1 + 2 + 3 + ... + n
        return dpTopDown(triangle);
    }
    
    // DP: Bottom Up    
    int dpBottomUp(vector<vector<int>> &triangle) {
        // Define of state dp[i][j]: the mininum path sum from position (i,j) to the last row
        vector<vector<int>> dp(row, vector<int>(col, INT_MAX));
        
        for(int i = 0; i < col; i++) {
            dp[row-1][i] = triangle[row-1][i];
        }
        
        for(int i = row - 2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        
        return dp[0][0];
    }

private:
    int row;
    int col;
};
~~~

## Similar problems
[Minimum Path Sum](https://www.lintcode.com/problem/minimum-path-sum/)  

## Tags
Dynamic Programming