# 573. Build Post Office II

## Description
~~~
Given a 2D grid, each cell is either a wall 2, an house 1 or empty 0 (the number zero, one, two), find a place to build a post office so that the sum of the distance from the post office to all the houses is smallest.

Return the smallest sum of distance. Return -1 if it is not possible.
~~~

**Example**
```
Given a grid:

0 1 0 0 0
1 0 0 2 1
0 1 0 0 0

return 8, You can build at (1,1). (Placing a post office at (1,1), the distance that post office to all the house sum is smallest.)
```
**Challenge**
Solve this problem within O(n^3) time.

## Link
[lintcode](https://www.lintcode.com/problem/build-post-office-ii/)  
## Method
1. BFS (Breadth First Search)   
Key point: the number of houses are much smaller than empty cells. Use houses as the BFS start point to calculate distance to each empty cells.

## Solution
1.1 BFS
~~~
enum celltype {
    EMPTY = 0,
    HOUSE = 1,
    WALL
};

struct Coordinate {
    int x, y;
    Coordinate(int _x, int _y) : x (_x), y(_y) {}
    Coordinate() : x (0), y(0) {}
};

class Solution {
public:
    /**
     * @param grid: a 2D grid
     * @return: An integer
     */
    int shortestDistance(vector<vector<int>> &grid) {
        // write your code here
        row = grid.size();
        col = grid[0].size();
        if (row == 0 || col == 0) {
            return -1;
        }

        vector<Coordinate> houses = getCells(grid, HOUSE);
        vector<Coordinate> empties = getCells(grid, EMPTY);
        
        vector<vector<int>> distances(row, vector<int>(col, 0));
        vector<vector<int>> visitedTimes(row, vector<int>(col, 0));
        
        // each house by BFS to get distances to all empties
        for (auto house : houses) {
            bfs(house, grid, distances, visitedTimes);
        }
        
        // each empty position, get sum of all distance for each house
        int shortest = INT_MAX;
        for (auto empty : empties) {
            // make sure all houses are reachable from empty position
            if (visitedTimes[empty.x][empty.y] != houses.size()) {
                continue;
            }
            shortest = min(shortest, distances[empty.x][empty.y]);
        }

        if (shortest == INT_MAX) {
            return -1;
        }
        
        return shortest;
    }
    
    void bfs(Coordinate& house, vector<vector<int>> &grid, vector<vector<int>> &distances, vector<vector<int>> &visitedTimes) {
        int deltaX[] = {1, 0, -1, 0};
        int deltaY[] = {0, 1, 0, -1};
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        queue<Coordinate> q;
        q.push(house);
        int distance = 0;
        
        while(!q.empty()) {
            distance++;
            int size = q.size();
            for(int k = 0; k < size; k++) {
                Coordinate curPos = q.front();
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int x = curPos.x + deltaX[i];
                    int y = curPos.y + deltaY[i];
                    Coordinate curCoordinate(x,y);
                    if (inBound(grid, curCoordinate) && !visited[x][y]) {
                        q.push(curCoordinate);
                        visitedTimes[x][y]++;
                        distances[x][y] += distance;
                        visited[x][y] = true;
                    }
                }
            }
        }
    }

private:
    bool inBound(vector<vector<int>>& grid, Coordinate pos) {
        if (pos.x < 0 || pos.x >= row || pos.y < 0 || pos.y >= col ) {
            return false;
        }
        return (grid[pos.x][pos.y] == EMPTY);
    }
    
    vector<Coordinate> getCells(vector<vector<int>>& grid, celltype type) {
        vector<Coordinate> result;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == type) {
                    result.push_back(Coordinate(i,j));
                }
            }
        }
        return result;
    }
    int row, col;

};
~~~

## Similar problems
[Build Post Office](https://www.lintcode.com/problem/build-post-office/)

## Tags
Breadth First Search 
