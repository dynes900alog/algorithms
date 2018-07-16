# 618. Search Graph Nodes

## Description

Given a undirected graph, a node and a target, return the nearest node to given node which value of it is target, return NULL if you can't find.

There is a mapping store the nodes' values in the given parameters.

**Notice**

It's guaranteed there is only one available solution

**Example**
```
2------3  5
 \     |  | 
  \    |  |
   \   |  |
    \  |  |
      1 --4
Give a node 1, target is 50

there a hash named values which is [3,4,10,50,50], represent:
Value of node 1 is 3
Value of node 2 is 4
Value of node 3 is 10
Value of node 4 is 50
Value of node 5 is 50

Return node 4
```

## Link
[lintcode](http://www.lintcode.com/en/problem/search-graph-nodes/)

## Method
1. BFS (Breadth First Search) 

Key point: 

## Solution
1.1 BFS
~~~
/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph a list of Undirected graph node
     * @param values a hash mapping, <UndirectedGraphNode, (int)value>
     * @param node an Undirected graph node
     * @param target an integer
     * @return the a node
     */
    UndirectedGraphNode* searchNode(vector<UndirectedGraphNode*>& graph,
                                    map<UndirectedGraphNode*, int>& values,
                                    UndirectedGraphNode* node,
                                    int target) {
          // Write your code here
        queue<UndirectedGraphNode*> Q;
        unordered_set<UndirectedGraphNode*> visited;
        Q.push(node);
        visited.insert(node);

        while(!Q.empty()) {
            UndirectedGraphNode* curNode = Q.front();
            Q.pop();
            if (values[curNode] == target) {
                return curNode;
            }

            for(auto neighbor : curNode->neighbors) {
                if (visited.count(neighbor) == 1) {
                    continue;
                }
                Q.push(neighbor);
                visited.insert(neighbor);
            }
        }
  
        return NULL;  
    }
};                                                                            
~~~

## Similar problems
[Connected Component in Undirected Graph](https://www.lintcode.com/problem/connected-component-in-undirected-graph/)

## Tags
Breadth First Search  