# 88. Lowest Common Ancestor of a Binary Tree

## Description
~~~
Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.

The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.

Assume two nodes are exist in tree.

Example
For the following binary tree:

  4
 / \
3   7
   / \
  5   6
LCA(3, 5) = 4

LCA(5, 6) = 7

LCA(6, 7) = 7


~~~

## Link
[lintcode](https://www.lintcode.com/problem/lowest-common-ancestor-of-a-binary-tree/)

## Method
1. divide and conquer 

Key point: 定义函数返回值：1. 找到返回LCA 2.只有NODE1 返回NODE1 3. 只有NODE2 返回NODE2 4.不存在，返回NULL 

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
    /*
     * @param root: The root of the binary search tree.
     * @param A: A TreeNode in a Binary.
     * @param B: A TreeNode in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
        // write your code here
        if (!root) {
            return NULL;    
        }
        
        // Any of A/B or (A is parent of B or reverse)
        if (root == A || root == B) {
            return root;
        }
        
        TreeNode* left = lowestCommonAncestor(root->left, A, B);
        TreeNode* right = lowestCommonAncestor(root->right, A, B);
        
        // find LCA
        if (left && right) {
            return root;
        }
        
        if (left) {
            return left;
        }
        
        if (right) {
            return right;
        }
        
        // not find
        return NULL;
    }
};
~~~

## Similar problems
[Lowest Common Ancestor II](https://www.lintcode.com/problem/lowest-common-ancestor-ii/)
[Lowest Common Ancestor III](https://www.lintcode.com/problem/lowest-common-ancestor-iii/)


## Tags
Binary Tree Traversal
