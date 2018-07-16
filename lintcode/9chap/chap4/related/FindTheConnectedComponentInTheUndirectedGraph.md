# 431. Find the Connected Component In The Undirected Graph

## Description
~~~
Find the number connected component in the undirected graph. Each node in the graph contains a label and a list of its neighbors. (a connected component (or just component) of an undirected graph is a subgraph in which any two vertices are connected to each other by paths, and which is connected to no additional vertices in the supergraph.)
~~~

**Example**
```
Given graph:

A------B  C
 \     |  |
  \    |  |
   \   |  |
    \  |  |
      D   E
Return {A,B,D}, {C,E}. Since there are two connected component which is {A,B,D}, {C,E}
```

## Link
[lintcode](https://www.lintcode.com/problem/find-the-connected-component-in-the-undirected-graph/)

## Method
1. BFS (Breadth First Search by level order)   
Key point: 
2. UF
Key point: 除了常规的BFS方法，还可以用Union Find。  
a.)两重循环遍历所有的node，并存入一个HashSet（为什么是HashSet，HashMap是否可以？）  
b.)用HashSet的元素初始化UnionFind（father HashMap的构建）
再度两重循环遍历所有node，将now node 和 neighbor node全部union起来  
c.)通过辅助函数print，对HashSet中的每一个节点进行父节点查找（find），把具有相同的父节点的子节点全部打包成ArrayList作为value，按照父节点的label为key，存入HashMap中，最后把这个HashMap的values打包成List，输出结果

## Solution
1.1 BFS (not verified by OJ)
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
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode *>& nodes) {
        // write your code here
        vector<vector<int>> components;
        unordered_set<UndirectedGraphNode*> visited;

        if (nodes.empty()) {
            return components;
        }

        for(const auto& node : nodes) {
            if (visited.find(node) != visited.end()) {
                continue;
            }
            vector<int> component = bfs(node, visited);
            // sort component
            sort(component.begin(), component.end());
            components.push_back(component);
        }

        return components;
    }

    vector<int> bfs(UndirectedGraphNode *node, unordered_set<UndirectedGraphNode*> visited) {
        vector<int> result;
        queue<UndirectedNode> q;
        q.push(node);

        while(!q.empty()) {
            UndirectedGraphNode* curNode = q.front();
            q.pop();
            for(const auto& neighbor : curNode->neighbors) {
                if (visited.find(neighbor) != visited.end()) {
                    continue;
                }
                q.push(neighbor);
                visited.insert(neighbor);    
            }
        }
        return result;
    }        
};

~~~
1.2 UF (Java code, not verified by OJ)
~~~
/**
 * Definition for Undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     ArrayList<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */
public class Solution {
    // Define UnionFind Class
    class UnionFind{
        HashMap<Integer, Integer> father = new HashMap<Integer, Integer>();
        UnionFind(HashSet<Integer> hashSet){
            for(Integer now : hashSet) {
                father.put(now, now);
            }
        }
        int find(int x){
            int parent =  father.get(x);
            while(parent!=father.get(parent)) {
                parent = father.get(parent);
            }
            return parent;
        }
        int compressed_find(int x){
            int parent =  father.get(x);
            while(parent!=father.get(parent)) {
                parent = father.get(parent);
            }
            int temp = -1;
            int fa = father.get(x);
            while(fa!=father.get(fa)) {
                temp = father.get(fa);
                father.put(fa, parent) ;
                fa = temp;
            }
            return parent;
        }
        void union(int x, int y){
            int fa_x = find(x);
            int fa_y = find(y);
            if(fa_x != fa_y)
            father.put(fa_x, fa_y);
        }
    }

    List<List<Integer>> print(HashSet<Integer> hashSet, UnionFind uf, int n) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        HashMap<Integer, List<Integer>> hashMap = new HashMap<Integer, List<Integer>>();
        for (int i : hashSet) {
            int fa = uf.find(i);
            if (!hashMap.containsKey(fa)) {
                hashMap.put(fa, new ArrayList<Integer>());
            }
            List<Integer> now = hashMap.get(fa);
            now.add(i);
            hashMap.put(fa, now);
        }
        for (List<Integer> now : hashMap.values()) {
            Collections.sort(now);
            ans.add(now);
        }
        return ans;
    }

    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    public List<List<Integer>> connectedSet(ArrayList<UndirectedGraphNode> nodes) {
        HashSet<Integer> hashSet = new HashSet<Integer>();
        for (UndirectedGraphNode now : nodes) {
            hashSet.add(now.label);
            for (UndirectedGraphNode neighbor : now.neighbors) {
                hashSet.add(neighbor.label);
            }
        }

        UnionFind uf = new UnionFind(hashSet);

        for (UndirectedGraphNode now : nodes) {
            for (UndirectedGraphNode neighbor : now.neighbors) {
                int fnow = uf.find(now.label);
                int fneighbor = uf.find(neighbor.label);
                if (fnow != fneighbor) {
                    uf.union(now.label, neighbor.label);
                }
            }
        }
        return print(hashSet, uf, nodes.size());
    }
}
~~~


## Similar problems
[Knight Shortest Path](https://www.lintcode.com/problem/knight-shortest-path/)

## Tags
Breadth First Search
