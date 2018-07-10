# 596. Minimum Subtree

## Description
~~~
Given a binary tree, find the subtree with minimum sum. Return the root of the subtree.

Example
Given a binary tree:

     1
   /   \
 -5     2
 / \   /  \
0   2 -4  -5 
return the node 1.


~~~

## Link
[lintcode](https://www.lintcode.com/problem/minimum-subtree)

## Method
1. divide and conquer + Traverse (global variable)
2. only D&C  (need to define ResultType class as the return value during D&C)

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
     * @param root: the root of binary tree
     * @return: the root of the minimum subtree
     */
    TreeNode * findSubtree(TreeNode * root) {
        // write your code here
        helper(root);
        return minRoot;
    }
    
    // 1. define function signature
    int helper(TreeNode *root) {
        // 3. exit condition
        if (!root) {
            return 0;
        }
        
        // 2. split
        int leftSum = helper(root->left);
        int rightSum = helper(root->right);
        
        int sum = root->val + leftSum + rightSum;
        if (sum < minSum) {
            minSum = sum;
            minRoot = root;
        }
        return sum;
    }
private:
    TreeNode *minRoot = nullptr;
    int minSum = INT_MAX;
};

~~~
1.2 D & C only (not compile/verify)
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
    TreeNode *minSubtree;
    int sum, minSum;
    ResultType(TreeNode *minSubtree, int minSum, int sum) {
        this->minSubtree = minSubtree;
        this->sum = sum;
        this->minSum = minSum;
    }
}

class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the minimum subtree
     */
    TreeNode * findSubtree(TreeNode * root) {
        // write your code here
        ResultType* result = helper(root);
        return result->minSubtree;
    }
    
    // 1. define function signature
    ResulType* helper(TreeNode *root) {
        // 3. exit condition
        if (!root) {
            return new ResultType(null, INT_MAX, 0);
        }
        
        // 2. split
        ResultType leftResult = helper(root->left);
        ResultType rightResult = helper(root->right);
        ResultType result = new ResultType(
            root,
            leftResult.sum + rightResult.sum + node.val,
            leftResult.sum + rightResult.sum + node.val 
            );

        if (leftResult.minSum < result.minSum) {
            result.minSum = leftResult.minSum;
            result.minSubtree = leftResult.minSubtree;
        }

        if (rightResult.minSum < result.minSum) {
            result.minSum = rightResult.minSum;
            result.minSubtree = rightResult.minSubtree;
        }

        return result;
    }
};
~~~

## Similar problems
[Maximum SubTree](https://www.lintcode.com/problem/maximum-subtree/)  

## Tags
Binary Tree Traversal
