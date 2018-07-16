# 69. Binary Tree Level Order Traversal

## Description
~~~
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

Example
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
 

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

Challenge
Challenge 1: Using only 1 queue to implement it.

Challenge 2: Use DFS algorithm to do it.
~~~

## Link
[lintcode](https://www.lintcode.com/problem/binary-tree-level-order-traversal/)

## Method
1. BFS (Breadth First Search) 
2. DFS

Key point: 
1. BFS by only one queue - how to keep each level's size of nodes so get the exact number of nodes in one level from Queue
2. DFS 

## Solution
1.1 BFS
~~~
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        // write your code here
        vector<vector<int>> result;
        if (!root) {
            return result;
        }
        
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()) {
            int qsize = q.size();
            vector<int> levelResult;

            for(int i = 0; i < qsize; i++) {
                TreeNode* node = q.front();
                q.pop();
                levelResult.push_back(node->val);
                if (node->left) {
                    q.push(node->left); 
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            
            result.push_back(levelResult);
        }
        
        return result;
    }
};    
~~~

## Similar problems
[Binary Tree Level Order Traversal II](https://www.lintcode.com/problem/binary-tree-level-order-traversal-ii)

## Tags
Breadth First Search
