# 97. Maximum Depth of Binary Tree

## Description
~~~
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example
Given a binary tree as follow:

  1
 / \ 
2   3
   / \
  4   5  
The maximum depth is 3.


~~~

## Link
[lintcode](https://www.lintcode.com/problem/maximum-depth-of-binary-tree)

## Method
1. divide and conquer 
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
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode * root) {
        // write your code here
        if (!root) {
            return 0;
        }
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return (left > right ? left + 1 : right + 1);
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
private:
    int depth;
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode * root) {
        // write your code here
        depth = 0;
        if (!root) {
            return 0;
        }

        helper(node, 1);
        return depth;        
    }

    void helper(TreeNode* node, int curDepth) {
        if (!node) {
            return;
        }
        
        if (curDepth > depth) {
            depth = curDepth;
        }

        helper(node->left, curDepth + 1);
        helper(node->right, curDepth + 1);
    }
};
~~~

## Similar problems
[Minimum Depth of Binary Tree](https://www.lintcode.com/problem/minimum-depth-of-binary-tree)  

## Tags
Binary Tree Traversal
