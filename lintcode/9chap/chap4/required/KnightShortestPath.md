# 611. Knight Shotest Path

## Description
~~~
Given a knight in a chessboard (a binary matrix with 0 as empty and 1 as barrier) with a source position, find the shortest path to a destination position, return the length of the route.
Return -1 if knight can not reached.
~~~

**Clarification**
```
If the knight is at (x, y), he can get to the following positions in one step:

(x + 1, y + 2)
(x + 1, y - 2)
(x - 1, y + 2)
(x - 1, y - 2)
(x + 2, y + 1)
(x + 2, y - 1)
(x - 2, y + 1)
(x - 2, y - 1)
```
**Example**
```
[[0,0,0],
 [0,0,0],
 [0,0,0]]
source = [2, 0] destination = [2, 2] return 2

[[0,1,0],
 [0,0,0],
 [0,0,0]]
source = [2, 0] destination = [2, 2] return 6

[[0,1,0],
 [0,0,1],
 [0,0,0]]
source = [2, 0] destination = [2, 2] return -1
```

## Link
[lintcode](https://www.lintcode.com/problem/knight-shortest-path/)

## Method
1. BFS (Breadth First Search by level order)   
Key point: 

## Solution
1.1 BFS (not verified by OJ)
~~~
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    /**
     * @param grid: a chessboard included 0 (false) and 1 (true)
     * @param source: a point
     * @param destination: a point
     * @return: the shortest path 
     */
    int shortestPath(vector<vector<bool>> &grid, Point &source, Point &destination) {
        // write your code here
        int row = grid.size();
        int col = grid[0].size();
        queue<Point> q;
        int distance = 0;
        
        if (row == 0 || col == 0) {
            return -1;
        }
        if (source.x == destination.x && source.y == destination.y) {
            return 0;
        }
        
        // vector<vector<int>> move = {{1,2}, {1,-2}, {-1,2}, {-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
        int move[8][2] =  {{1,2}, {1,-2}, {-1,2}, {-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
        q.push(source);
        
        while(!q.empty()) {
            distance++;
            int size = q.size();

            // BFS by level order
            for(int i = 0; i < size; i++) {
                Point pos = q.front();
                q.pop();
                // traverse all neighbors and enqueue them 
                for(int j = 0; j < 8; j++) {
                    Point neighbor(pos.x + move[j][0], pos.y + move[j][1]);
                    if (!inBound(grid,neighbor)) {
                        continue;
                    }
                    if (neighbor.x == destination.x && neighbor.y == destination.y) {
                        return distance;
                    }
                    q.push(neighbor);
                    grid[neighbor.x][neighbor.y] = 1;
                }
            }
        }
        
        return -1;
    }
    
    bool inBound(vector<vector<bool>> &grid, Point &point) {
        int row = grid.size();
        int col = grid[0].size();
        if (point.x < 0 || point.x >= row || point.y < 0 || point.y >= col) {
            return false;
        }
        
        return  (grid[point.x][point.y] == 0);
    }
};

~~~

## Similar problems
[Knight Shortest Path II](https://www.lintcode.com/problem/knight-shortest-path-ii/)

## Tags
Breadth First Search
