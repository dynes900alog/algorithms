# 137. Clone Graph

## Description
~~~
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

How we serialize an undirected graph:

Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.

As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

   1
  / \
 /   \
0 --- 2
     / \
     \_/
~~~

## Link
[lintcode](https://www.lintcode.com/problem/clone-graph/)

## Method
1. BFS (Breadth First Search)   
Key point: Need to copy both nodes and edges.   
1.)  BFS to get all the nodes of current graph to clone nodes, set up mapping between old nodes and new nodes  
2.) Set up connection of nodes (copy edges).

2. DFS (not recommend)

## Solution
1.1 BFS
~~~
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */


class Solution {
public:
    /*
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        // write your code here   
        if (!node) {
            return NULL;
        }
        
        // BFS to traverse/get all nodes of current graph
        vector<UndirectedGraphNode *> nodes = getGraphNodes(node);
        
        // Clone all nodes and mappings from old -> new
        vector<UndirectedGraphNode *> cloneNodes;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
        for(auto element : nodes) {
            UndirectedGraphNode* newNode = new UndirectedGraphNode(element->label);
            cloneNodes.push_back(newNode);
            map[element] = newNode;
        }

        // Clone graph's edge
        for(auto element : nodes) {
            for(auto neighbor : element->neighbors) {
               UndirectedGraphNode* cloneElement = map[element];
               UndirectedGraphNode* cloneNeighbor = map[neighbor];
               cloneElement->neighbors.push_back(cloneNeighbor);
            }
        }    
        
        return map[node];
    }
    
    // BFS to traverse all nodes
    vector<UndirectedGraphNode*> getGraphNodes(UndirectedGraphNode *node) {
        vector<UndirectedGraphNode*> result;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        unordered_set<UndirectedGraphNode *> set;
        set.insert(node);
        
        while(!q.empty()) {
            UndirectedGraphNode* node = q.front();
            result.push_back(node);
            q.pop();
            for(auto element : node->neighbors) {
                if (set.count(element) == 1) {
                    continue;
                }
                set.insert(element);
                q.push(element);
            }
        }
        
        return result;
    }
};

~~~


1.2 DFS
~~~
// DFS 版本的解法 (copy from 9 chapters)
class Solution {
public:
    UndirectedGraphNode *clone(UndirectedGraphNode *node, map<int,UndirectedGraphNode*> &table)
    {
        if(node==NULL)
            return NULL;
            
        if(table.find(node->label)!=table.end())
            return table[node->label];
        
        UndirectedGraphNode *newnode=new UndirectedGraphNode(node->label);
        table[newnode->label]=newnode;

        for(int i=0;i<node->neighbors.size();i++)
        {
            UndirectedGraphNode *neighbor=clone(node->neighbors[i],table);
            newnode->neighbors.push_back(neighbor);
        }
        
        return newnode;
    }
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map<int,UndirectedGraphNode*> visitTable;
        return clone(node,visitTable);
    }
};
~~~

## Similar problems
[Copy List with Random Pointer](https://www.lintcode.com/problem/copy-list-with-random-pointer/)

## Tags
Breadth First Search  
