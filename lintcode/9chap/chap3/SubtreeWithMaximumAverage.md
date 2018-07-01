# 597. Subtree with Maximum Average

## Description
~~~
Given a binary tree, find the subtree with maximum average. Return the root of the subtree.

Example
Given a binary tree:

     1
   /   \
 -5     11
 / \   /  \
1   2 4    -2 
return the node 11.


~~~

## Link
[lintcode](https://www.lintcode.com/problem/subtree-with-maximum-average)

## Method
1. divide and conquer + traverse

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

class ResultType {
public:    
    int sum;
    int nodes;
    ResultType():sum(0), nodes(0) {}
    ResultType(int sum1, int nodes1): sum(sum1), nodes(nodes1) {} 
};     

class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the maximum average of subtree
     */
    TreeNode * findSubtree2(TreeNode * root) {
        // write your code here
        helper(root);
        return maxSubtree;
    }
    
    ResultType helper(TreeNode *root) {
        if (!root) {
           return (ResultType(0, 0)); 
        }
        
        // 2. split
        ResultType left = helper(root->left);
        ResultType right = helper(root->right);
        
        ResultType current = ResultType(left.sum + right.sum + root->val, 
                                        1 + left.nodes + right.nodes);
        
        // check the NULL condition of the final return. Also use multiply instead of divid to avoid using float precision issue 
        if (maxSubtree == NULL || 
            (current.sum * subtreeResult.nodes > subtreeResult.sum * current.nodes)
           ) {
            subtreeResult = current;
            maxSubtree = root;
        }
        
        return current;
    }

private:
    ResultType subtreeResult;
    TreeNode* maxSubtree = nullptr;
};
~~~

## Similar problems
[Maximum SubTree](https://www.lintcode.com/problem/maximum-subtree/)  

## Tags
Binary Tree Traversal
