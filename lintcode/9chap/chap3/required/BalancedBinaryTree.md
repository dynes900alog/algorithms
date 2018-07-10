# 93. Balanced Binary Tree

## Description
~~~
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example
Given binary tree A = {3,9,20,#,#,15,7}, B = {3,#,20,15,7}

A)  3            B)    3 
   / \                  \
  9  20                 20
    /  \                / \
   15   7              15  7
The binary tree A is a height-balanced binary tree, but B is not.

~~~

## Link
[lintcode](https://www.lintcode.com/problem/balanced-binary-tree)

## Method
1. divide and conquer: depth of abs(left - right) <= 1 
2. 

Key point:  

## Solution
1.1 Divide and Conquer + Traverse
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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode * root) {
        // write your code here
        return (depth(root) != -1);
    }
    
    int depth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        int left = depth(root->left);
        int right = depth(root->right);
        
        if (left == -1 || right == -1 || abs(left - right) > 1) {
            return -1;
        }
        
        return max(left, right) + 1;
    }
};
~~~

## Similar problems
[Complete Binary Tree](https://www.lintcode.com/problem/complete-binary-tree/)  
[Validate Binary Search Tree](https://www.lintcode.com/problem/validate-binary-search-tree/)  

## Tags
Binary Tree Traversal
