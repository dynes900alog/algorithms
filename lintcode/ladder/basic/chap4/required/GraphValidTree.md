# 178. Graph Valid Tree

## Description
~~~
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Example
Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

~~~

## Link
[lintcode](https://www.lintcode.com/problem/graph-valid-tree/)

## Method
1. BFS (Breadth First Search) 

Key point: 
The conditions for a Tree: 
a. Number of edges is: "nodes - 1"
b. All nodes are connected

2. Union Find


## Solution
1.1 BFS
~~~
class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        bool result = false;
        if (n == 0) {
            return result;
        }
        
        // 1. edges = n - 1
        if (edges.size() != n - 1) {
            return result;
        }
        
        // 2. BFS to check if all nodes are connected        
        map<int, set<int>> graph = graphInit(n, edges);
        queue<int> q;
        q.push(0);
        
        /* For recording visited nodes, either unordered_set or vector are ok here     unordered_set<int> visited;
         visited.insert(0);
        */
        vector<bool> visited(n, false);
        visited[0] = true;
        int connectedNodes = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            connectedNodes++;
            for( int neighbor : graph[node]) {
                //if (visited.count(neighbor) == 1) {
                if (visited[neighbor] == true) {
                    continue;
                }
                // visited.insert(neighbor);
                visited[neighbor] = true;
                q.push(neighbor);
            }
            
        }

        result = (connectedNodes == n);
        return result;
    }

    // Helper function to create graph (adjacent matrix)
    map<int, set<int>> graphInit(int nodes, vector<vector<int>> edges) {
        map<int, set<int>> result;
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            result[u].insert(v);  
            result[v].insert(u);
        }
        
        return result;
    }
};
~~~

1.2 Union and Find
~~~
class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        return validTreeUF(n, edges);
    }
    
    // Union and Find: Tree conditions: 
    // 1. number of edges is n - 1 
    // 2. a pair of new nodes' (suppose no dumplicated nodes in edges) parent are different except root
    bool validTreeUF(int n, vector<vector<int>> &edges) {    
        if (n == 0) {
            return false;
        }
        
        if (edges.size() != n -1) {
            return false;
        }
        
        vector<int> root(n, -1);
        
        for(int i = 0; i < edges.size(); i++) {
            // Find
            int root1 = find(root, edges[i][0]);
            int root2 = find(root, edges[i][1]);
            if (root1 == root2) {
                return false;
            }
            // Union
            root[root1] = root2;
        }
        
       return true; 
    } 
    
    int find(vector<int> &root, int node) {
        if (root[node] == -1) {
            return node;
        }
        else {
            return find(root, root[node]);
        }
    }
};
~~~

## Similar problems
[Connected Component in Undirected Graph](https://www.lintcode.com/problem/connected-component-in-undirected-graph/)

## Tags
Breadth First Search  
Union and Find
