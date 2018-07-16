# 433. Number of Islands

## Description
~~~
Given a boolean 2D matrix, 0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent.

Find the number of islands.
~~~

**Example**
```
Given graph:

[
  [1, 1, 0, 0, 0],
  [0, 1, 0, 0, 1],
  [0, 0, 0, 1, 1],
  [0, 0, 0, 0, 0],
  [0, 0, 0, 0, 1]
]
return 3.
```

## Link
[lintcode](https://www.lintcode.com/problem/number-of-islands)  
## Method
1. BFS (Breadth First Search)   
Key point: 

2. DFS (not recommend, if the matrix is big enough, it easily casues stack overflow. DFS depth too big - for example, matrix with all "1"s, depth = m*n)

3. UF
## Solution
1.1 BFS
~~~
class Solution {
public:
struct Coordinate {
    int x;
    int y;
    Coordinate(int x1, int y1): x(x1), y(y1) {}
    Coordinate(): x(0), y(0) {}
};

    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    int numIslands(vector<vector<bool>> &grid) {
        // write your code here
        // DFS
        // return numIslandsDFS(grid);
        return numIslandsBFS(grid);
    }
    
    int numIslandsBFS(vector<vector<bool>> &grid) {
        int answer = 0;
        row = grid.size();
        if (row == 0) {
            return answer;
        }
        col = grid[0].size();
        if (col == 0) {
            return answer;
        }

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 0) {
                    continue;
                }
                // mark all neighbors of the current node
                markIslands(grid, i, j);
                answer++;
            }
        }
        
        return answer;
    }    
    

    // Use BFS to mark (set color) all its neighbors
    void markIslands(vector<vector<bool>> &grid, int posX, int posY) {
        if (!grid[posX][posY]) {
            return;
        }
        
        int deltX[] = {0, 1, -1, 0};
        int deltY[] = {1, 0, 0, -1};
        
        queue<Coordinate> Q;
       
        Q.push(Coordinate(posX, posY));
        grid[posX][posY] = 0;
        
        while(!Q.empty()) {
            Coordinate element = Q.front();
            Q.pop();
            for(int i = 0; i < 4; i++) {
                int x = element.x + deltX[i];
                int y = element.y + deltY[i];
                // out of bound
                if (x < 0 || x >= row || y < 0 || y >= col) {
                    continue;
                }
                if (grid[x][y] == 1) {
                    grid[x][y] = 0;
                    Q.push(Coordinate(x,y));
                }
            }
        }
    }
};    

~~~
1.2 DFS
~~~
class Solution {
public:
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    int numIslands(vector<vector<bool>> &grid) {
        // write your code here
        int answer = 0;
        row = grid.size();
        if (row == 0) {
            return answer;
        }
        col = grid[0].size();
        if (col == 0) {
            return answer;
        }

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if (grid[i][j] == false) {
                    continue;
                }
                answer++;
                dfs(grid, i, j);
            }
        }
        
        return answer;
    }
    
    void dfs(vector<vector<bool>> & grid, int i, int j) {
        if (i < 0 || i >= row || j < 0 || j >= col) {
            return;
        }
        
        if (grid[i][j] == true) {
            grid[i][j] = false;
            dfs(grid, i+1, j);
            dfs(grid, i-1, j);
            dfs(grid, i, j-1);
            dfs(grid, i, j+1);
        }
    }
private:
    int row, col;
};
~~~

1.3 Union and Find (Java code, not verified.)
~~~
class UnionFind { 

    private int[] father = null;
    private int count;

    private int find(int x) {
        if (father[x] == x) {
            return x;
        }
        return father[x] = find(father[x]);
    }

    public UnionFind(int n) {
        // initialize your data structure here.
        father = new int[n];
        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }
    }

    public void connect(int a, int b) {
        // Write your code here
        int root_a = find(a);
        int root_b = find(b);
        if (root_a != root_b) {
            father[root_a] = root_b;
            count --;
        }
    }
        
    public int query() {
        // Write your code here
        return count;
    }
    
    public void set_count(int total) {
        count = total;
    }
}

public class Solution {
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    public int numIslands(boolean[][] grid) {
        int count = 0;
        int n = grid.length;
        if (n == 0)
            return 0;
        int m = grid[0].length;
        if (m == 0)
            return 0;
        UnionFind union_find = new UnionFind(n * m);
        
        int total = 0;
        for(int i = 0;i < grid.length; ++i)
            for(int j = 0;j < grid[0].length; ++j)
            if (grid[i][j])
                total ++;
    
        union_find.set_count(total);
        for(int i = 0;i < grid.length; ++i)
            for(int j = 0;j < grid[0].length; ++j)
            if (grid[i][j]) {
                if (i > 0 && grid[i - 1][j]) {
                    union_find.connect(i * m + j, (i - 1) * m + j);
                }
                if (i <  n - 1 && grid[i + 1][j]) {
                    union_find.connect(i * m + j, (i + 1) * m + j);
                }
                if (j > 0 && grid[i][j - 1]) {
                    union_find.connect(i * m + j, i * m + j - 1);
                }
                if (j < m - 1 && grid[i][j + 1]) {
                    union_find.connect(i * m + j, i * m + j + 1);
                }
            }
        return union_find.query();
    }
}
~~~

## Similar problems
[Number of Islands II](https://www.lintcode.com/problem/number-of-islands-ii)

## Tags
Breadth First Search
DFS and UF  
