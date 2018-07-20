# 33. N-Queens

## Description
~~~
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
~~~

**Example**
```
There exist two distinct solutions to the 4-queens puzzle:

[
  // Solution 1
  [".Q..",
   "...Q",
   "Q...",
   "..Q."
  ],
  // Solution 2
  ["..Q.",
   "Q...",
   "...Q",
   ".Q.."
  ]
]

```
**Challenge**  
Can you do it  without recursion?

## Link
[lintcode](https://lintcode.com/problem/n-queens/)

## Method
Permuation problem
1. DFS by recursion  
key point: check diagnol positions  

## Solution
1.1 DFS
~~~
class Solution {
public:
    /*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
    vector<vector<string>> solveNQueens(int n) {
        // write your code here
        int rows = 0;
        vector<vector<string>> result;
        // for all rows, only need to record the colum positions
        vector<int> cols;

        dfsHelper(result, cols, n);
        
        return result;
    }

    // Permutation template
    void dfsHelper(vector<vector<string>>& result, vector<int> &cols, int queens) {
        if (cols.size() == queens) {
            result.push_back(convertResult(cols));
            return;
        }
        
        for(int i = 0; i < queens; i++) {
            if (!isValidPosition(cols, i)) {
                continue;
            }    
            cols.push_back(i);
            dfsHelper(result, cols, queens);
            cols.pop_back();
        }
    }
    
    bool isValidPosition(vector<int>& cols, int col) {
        // current row
        int row = cols.size();
        for(int i = 0; i < cols.size(); i++) {
            if (cols[i] == col) {
                return false;
            }
            
            // diagnol positions
            if (row -i == col - cols[i] ||
                row -i == cols[i] - col) {
                return false;
            }
        }
        
        return true;
    }
    
    vector<string> convertResult(vector<int> &cols) {
        vector<string> record;
        // row by row convert
        for(int i = 0; i < cols.size(); i++) {
            string temp(cols.size(), '.');
            temp[cols[i]] = 'Q';
            record.push_back(temp);
        }
        
        return record;
    }
};
~~~

1.2 Non recursion solution
~~~
class Solution {
public:
    /*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
    vector<vector<string>> solveNQueens(int n) {
        // write your code here
        int rows = 0;
        vector<vector<string>> result;
        // for each row, record the colum positions
        vector<int> cols;
        
        // Non recursion solution
        stack<int> s;
        bool nextRowFlag = false;
        
        // stack is used for the trying colum of current row
        s.push(0);
        
        while(!s.empty()) {
            int col = s.top();
            s.pop();
            nextRowFlag = false;
            
            for(int i = col; i < n; i++) {
                if (isValidPosition(cols, i)) {
                    cols.push_back(i);
                    // save next trying colums for other possible solution
                    s.push(i+1);
                    nextRowFlag = true;
                    break;
                }
            }
            
            // one solution: save and go back one row to check other possible solutions
            if (cols.size() == n) {
                result.push_back(convertResult(cols));
                cols.pop_back();
                continue;
            }
            
            if (nextRowFlag) {
                s.push(0);
            }
            else {
                cols.pop_back();
            }
        }
        
        return result;
    }

    void dfsHelper(vector<vector<string>>& result, vector<int> &cols, int queens) {
        if (cols.size() == queens) {
            result.push_back(convertResult(cols));
            return;
        }
        
        for(int i = 0; i < queens; i++) {
            if (isValidPosition(cols, i)) {
                cols.push_back(i);
                dfsHelper(result, cols, queens);
                cols.pop_back();
            }
        }
    }
    
    bool isValidPosition(vector<int>& cols, int col) {
        // current row
        int row = cols.size();
        for(int i = 0; i < cols.size(); i++) {
            if (cols[i] == col) {
                return false;
            }
            
            // diagnol positions: "x + y" and "x - y"
            if (row - col ==  i - cols[i] ||
                row + col == i + cols[i]) {
                return false;
            }
        }
        
        return true;
    }
    
    vector<string> convertResult(vector<int> &cols) {
        vector<string> record;
        // row by row convert
        for(int i = 0; i < cols.size(); i++) {
            string temp(cols.size(), '.');
            temp[cols[i]] = 'Q';
            record.push_back(temp);
        }
        
        return record;
    }
};
~~~ 
## Similar problems
[Permutations](https://lintcode.com/problem/n-queens-ii/)

## Tags
DFS  
Permutation
