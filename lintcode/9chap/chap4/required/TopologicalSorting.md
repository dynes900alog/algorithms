# 127. Topological Sorting

## Description
Given an directed graph, a topological order of the graph nodes is defined as follow:

For each directed edge A -> B in graph, A must before B in the order list.
The first node in the order can be any node in the graph with no nodes direct to it.
Find any topological order for the given graph.

**Clarification**
[Learn more about representation of graphs](http://www.lintcode.com/help/graph)

**Example**
For graph as follow:

![alt text](images.jpg)

The topological order can be:
```
[0, 1, 2, 3, 4, 5]
[0, 2, 3, 1, 5, 4]
```
**Chanllenge**
Can you do it in both BFS and DFS?

## Link
[lintcode](https://www.lintcode.com/problem/topological-sorting)

## Method
1. BFS (Breadth First Search)   
Key point: indegree/outdegree concepts of directed graph - topological sorting is the fact that starting from node where "indegree = 0", update their neighbors by decreasing nodes' indegrees and continue following the nodes with "inedgrees = 0"

2. DFS 

## Solution
1.1 BFS
~~~
/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        // write your code here
        // 1. get indegree of all nodes 2. Put all indgrees equal 0 into queue and result 3. BFS for the graph, update indgrees,queue and result
        
        map<DirectedGraphNode*, int> indegrees;
        vector<DirectedGraphNode*> result;
        
        if (graph.size() == 0) {
            return result;
        }
        
        // Get indegree for all nodes
        indegrees = getIndgrees(graph);
        
        // Queue with indgree = 0
        queue<DirectedGraphNode*> Q;
        for(DirectedGraphNode* node : graph) {
            if (indegrees[node] == 0) {
                Q.push(node);
                result.push_back(node);
            }
        }
        
        // BFS to get all nodes
        while(!Q.empty()) {
            DirectedGraphNode* node = Q.front();
            Q.pop();
            
            for(DirectedGraphNode* neighbor : node->neighbors) {
                indegrees[neighbor]--;
                if (indegrees[neighbor] == 0) {
                    Q.push(neighbor);
                    result.push_back(neighbor);
                }
            }
        }
        
        return result;
    }
    
    
    map<DirectedGraphNode*, int> getIndgrees(vector<DirectedGraphNode*>& graph) {
        map<DirectedGraphNode*, int> result;

        /* Initilaize
        for(DirectedGraphNode* node : graph) {
            for(DirectedGraphNode* neighbor : node->neighbors) {
                result[neighbor] = 0;
            }
        }
        */

        for(DirectedGraphNode* node : graph) {
            for(DirectedGraphNode* neighbor : node->neighbors) {
                // or "result.count(neighbor) == 0/1"
                if (result.find(neighbor) != result.end()) {
                    result[neighbor]++;
                }
                else {
                    result[neighbor] = 1;
                }
            }
        }
        
        return result;
    }
};
~~~


1.2 DFS
~~~
/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        vector<DirectedGraphNode*> answer;
        map<DirectedGraphNode*, int> indegrees;
           
        //get all nodes where indegree is 0
        for(int i = 0; i < graph.size(); i++) {
            DirectedGraphNode* node = graph[i];
            for(int j = 0; j < node->neighbors.size(); j++) {
                DirectedGraphNode* neighbor = node->neighbors[j];
                if (indegrees.count(neighbor) == 0) {
                    indegrees[neighbor] = 1;
                }
                else {
                    indegrees[neighbor]++;
                }
            }   
        }
           
       // DFS for all nodes where indegree is 0
       for (int i = 0; i < graph.size(); i++) {
           if (indegrees[graph[i]] == 0) {
               dfs(graph[i], answer, indegrees);
           }
       }
           
       return answer;
    }  
      
      
    void  dfs(DirectedGraphNode* node, vector<DirectedGraphNode*> &answer, map<DirectedGraphNode*, int> &indegrees) {
          
        answer.push_back(node);
        // Note: decrease to negative value to avoid to add multiple times
        indegrees[node]--;
        
        for(int i = 0; i < node->neighbors.size(); i++) {
            DirectedGraphNode* neighbor = node->neighbors[i];
            indegrees[neighbor]--;
            if (indegrees[neighbor] == 0) {
                dfs(neighbor, answer, indegrees);
            }
        }
      }
};        
~~~

## Similar problems
[Course Schedule I](https://www.lintcode.com/problem/course-schedule/)
[Course Schedule II](https://www.lintcode.com/problem/course-schedule-ii/)
[Sequence Reconstruction](https://www.lintcode.com/problem/sequence-reconstruction/)

## Tags
Breadth First Search  
