# 598. Zombie in Matrix

## Description
~~~
Given a 2D grid, each cell is either a wall 2, a zombie 1 or people 0 (the number zero, one, two).Zombies can turn the nearest people(up/down/left/right) into zombies every day, but can not through wall. How long will it take to turn all people into zombies? Return -1 if can not turn all people into zombies.
~~~

**Example**
```
Given a matrix:

0 1 2 0 0
1 0 0 2 1
0 1 0 0 0
return 2
```

## Link
[lintcode](https://www.lintcode.com/problem/zombie-in-matrix/)

## Method
1. BFS (Breadth First Search)   
Key point: 

## Solution
1.1 BFS (not verified by OJ)
~~~
structure Coordinate {
    int x, y;
    Coordinate(int _x, int _y): x(_x) : y (_y) {}
};

class Solution {
public:
    int PEOPLE = 0;
    int ZOMBIE = 1;
    int WALL = 2;
    
    /**
     * @param grid  a 2D integer grid
     * @return an integer
     */
    int zombie(vector<vector<int>>& grid) {
        // Write your code here
        int row = grid.size();
        int col = grid[0].size();
        if (row == 0 || col == 0) {
            return 0;
        }

        int result = 0;
        /* Or use 2D array (4x2)
         vector<vector<int>> move = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
         */
        int deltaX = {1, 0, -1, 0};
        int deltaY = {0, 1,  0, -1};
        // enqueue all zombies 
        queue<Coordinate> q = findAllZombies(grid, row, col);

        // BFS to traverse matrix (level order)
        while(!q.empty()) {
            result++;
            int size = q.size();
            for (int i = 0; i < size; i++>) {
                Coordinate pos = q.front();
                q.pop();
                // mark all neighbors
                for(int j = 0; j < 4; j++>) {
                    int x = pos.x + deltaX[j];
                    int y = pos.y + deltaY[j];
                    Coordinate adj(x,y);
                    if(!isPeople(adj, grid)) {
                        continue;
                    }
                    grid[x][y] = ZOMBIE;
                    q.push(Coordinate(x,y));
                }
            }
        }

        /*
           Check any case where can't mark (another solution is to get number of  
           people at first, people-- during BFS and check if "people == 0" here)  
        */
        for(int i = 0; i < row; i++>) {
            for(int j = 0; j < col; j++>) {
                if (grid[i][j] == 0)
                    return -1;
            }
        }

        return result;
    }


    queue<Coordinate> findAllZombies(vector<vector<int>>& gird, int row, int col) {
        queue<Coordinate> q;
        for(int i = 0; i < row; i++>) {
            for(int j = 0; j < col; j++>) {
                if (grid[i][j] == 1) {
                    q.push(Coordinate(i,j));
                }
            }
        }
        return q;
    }

    bool isPeople(Coordinate coor, vector<vector<int>> &grid) {
        int n = grid.length;
        int m = grid[0].length;
        
        if (coor.x < 0 || coor.x >= n) {
            return false;
        }
        if (coor.y < 0 || coor.y >= m) {
            return false;
        }
        return (grid[coor.x][coor.y] == PEOPLE);
    }
};    

~~~

## Similar problems
[Number of Islands II](https://www.lintcode.com/problem/number-of-islands-ii)

## Tags
Breadth First Search
