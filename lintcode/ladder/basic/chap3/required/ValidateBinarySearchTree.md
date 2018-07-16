# 95. Validate Binary Search Tree

## Description
~~~
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
A single node tree is a BST

Example
An example:

  2
 / \
1   4
   / \
  3   5
The above binary tree is serialized as {2,1,4,#,#,3,5} (in level order).

~~~

## Link
[lintcode](https://www.lintcode.com/problem/validate-binary-search-tree)

## Method
1. divide and conquer (The prefered method)
Key point: 定义函数返回值, left/right's min/max value and state of BST
2. Traverse (Not recommend: this method has issue if only one root node existing and value is INT_MIN/INT_MAX)
Key point: with max/min value as input parameters
3. Traverse (inOrder)
Key point: 1. 对一个BST进行inorder traverse，必然会得到一个严格单调递增序列，否则则是invalid BST。 2. Inorder traverse时并不需要记录下整个访问过的序列，而只需要保存前一个访问的节点数值就可以了。

## Solution
1.1  divide and conquer
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
class ResultType {
public:
    TreeNode* minNode;
    TreeNode* maxNode;
    bool isBst;
    ResultType():minNode(NULL), maxNode(NULL), isBst(true) {}
};

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode * root) {
        write your code here
        ResultType result = helper(root);
        return result.isBst;
    }
    
    ResultType helper(TreeNode* root) {
        ResultType result;
        if (!root) {
            return result;
        }
        
        ResultType leftResult = helper(root->left);
        ResultType rightResult = helper(root->right);

        if (!leftResult.isBst || !rightResult.isBst) {
            result.isBst = false;
            return result;
        }
        
        if ((leftResult.maxNode != NULL && root->val <= leftResult.maxNode->val) ||
            (rightResult.minNode != NULL && root->val >= rightResult.minNode->val)) {
            result.isBst = false;
            return result;
        }
 
        result.isBst = true;       
        result.minNode = (leftResult.minNode == NULL) ? root : leftResult.minNode;
        result.maxNode = (rightResult.maxNode == NULL) ? root : rightResult.maxNode;
        
        return result;
    }
~~~    

1.2 Traversal
~~~
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode * root) {
        // write your code here
         return traverse(root, INT_MIN, INT_MAX);
    }
    
    bool traverse(TreeNode *root, int minVal, int maxVal) {
        if(!root) {
            return true;
        }    
        
        if(root->val <= minVal || root->val >= maxVal) {
            return false;
        }    
        
        return traverse(root->left, minVal, root->val) && traverse(root->right, root->val, maxVal);
    }
};
~~~

1.3 Inorder Traverse
~~~
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode * root) {
        // write your code here
        int curMax = INT_MIN;
        return inOrder(root, curMax);
    }
    
    
    // Inorder has increasing property
    bool inOrder(TreeNode* root, int &curMax) {
        if (!root) {
            return true;
        }
        
        if (!inOrder(root->left, curMax)) {
            return false;
        }

        // corner case: only one root node with value INT_MIN
        if (root->val == INT_MIN && curMax == INT_MIN)
            return true;

        if (root->val <= curMax) {
            return false;
        }
        
        curMax = root->val;
        
        return inOrder(root->right, curMax);
    }
};
~~~

## Similar problems
[Balanced Binary Tree](https://www.lintcode.com/problem/balanced-binary-tree)


## Tags
Binary Tree Traversal + Divide and Conquer
