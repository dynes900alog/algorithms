# 480. Binary Tree Paths

## Description
~~~
Given a binary tree, return all root-to-leaf paths.

Example
Given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

[
  "1->2->5",
  "1->3",
]
~~~

## Link
[lintcode](https://www.lintcode.com/problem/binary-tree-paths)

## Method
1. divide and conquer (easy to do) 
2. recursive traversal  (need global variable for)

Key point: Both are DFS and recursive implementation (D&Q or traversal) 

## Solution
1.1 Divide and Conquer
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
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode * root) {
        return binaryTreePathsDFS(root);
    }
    
    vector<string> binaryTreePathsDFS(TreeNode* root) {
        vector<string> paths;

        if (!root) {
            return paths;    
        }
        // Exit: leaf node        
        if (!root->left && !root->right) {
            paths.push_back(to_string(root->val));
            return paths;
        }
        
        vector<string> leftPath;
        vector<string> rightPath;
        
        leftPath = binaryTreePathsDFS(root->left);
        rightPath = binaryTreePathsDFS(root->right);
        
        for(auto &path : leftPath) {
            paths.push_back(to_string(root->val) + "->" + path);
        }

        for(auto &path : rightPath) {
            paths.push_back(to_string(root->val) + "->" + path);
        }
        
        return paths;
    }
};
~~~

1.2 Traversal
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
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode * root) {
        return binaryTreePathsTraversal(root);
    }
    
    vector<string> binaryTreePathsTraversal(TreeNode* root) {
        if (!root) {
            return result;
        }
        
        string path = to_string(root->val);
        traverse(root, path);

        return result;
    }
    
    // path: current path at node (include node)
    void traverse(TreeNode *node, string path) {
        if (!node) {
            return;
        }
        
        // Exit: leaf node, add to result and return
        if (!node->left && !node->right) {
            result.push_back(path);
            return;
        }
        
        if (node->left) {
            string lpath = path + "->" + to_string(node->left->val);
            traverse(node->left, lpath);
        }
        if (node->right) {
            string rpath = path + "->" + to_string(node->right->val);
            traverse(node->right, rpath);
        }
    }
private:
    vector<string> result;
};
~~~

## Similar problems

## Tags
Binary Tree Traversal
