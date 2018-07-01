# 453. Flatten Binary Tree to Linked List

## Description
~~~
Flatten a binary tree to a fake "linked list" in pre-order traversal.

Here we use the right pointer in TreeNode as the next pointer in ListNode.

Example

            1
               \
     1          2
    / \          \
   2   5    =>    3
  / \   \          \
 3   4   6          4
                     \
                      5
                       \
                        6


Challenge
Do it in-place without any extra memory.

~~~

## Link
[lintcode](https://www.lintcode.com/problem/minimum-subtree)

## Method
1. divide and conquer 
2. non recursive traverse
3. recursive traverse (not recommend)

Key point:  Divide & Conqer (1.function signature return last node 2. merge/connect nodes )

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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode * root) {
        // write your code here
        dfs(root);
    }
    
    // step 1. return last node of flattened Linked List
    TreeNode* dfs(TreeNode* root) {
        // 3. exit
        if (!root) {
            return nullptr;
        }

        // 2. split and connect nodes        
        TreeNode* leftLast = dfs(root->left);
        TreeNode* rightLast = dfs(root->right);
        
        // connect
        if (leftLast) {
            leftLast->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
     
        if (rightLast) {
            return rightLast;
        }
        
        if (leftLast) {
            return leftLast;
        }
        
        return root;
    }
};

~~~
1.2 Non recursive traverse
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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode * root) {
        // write your code here
        traverse(root);    
    }
    
    void traverse(TreeNode* root) {
        stack<TreeNode*> s;
        if (!root) {
            return;
        }
        s.push(root);
        
        while(!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            if (node->right) {
                s.push(node->right);
            }
            if (node->left) {
                s.push(node->left);
            }
            
            // connect nodes
            node->left = NULL;
            if (s.empty()) {
                node->right = NULL;
            }
            else {
                node->right = s.top();
            }
        }
    }
};
~~~

## Similar problems
[Convert Binary Search Tree to Doubly Linked List](https://www.lintcode.com/problem/convert-binary-search-tree-to-doubly-linked-list/)  

## Tags
Binary Tree Traversal
