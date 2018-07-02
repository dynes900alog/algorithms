# 595. Binary Tree Longest Consecutive Sequence

## Description
~~~
Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

Example
For example,

   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.

   2
    \
     3
    / 
   2    
  / 
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.


~~~

## Link
[lintcode](https://www.lintcode.com/problem/binary-tree-longest-consecutive-sequence/)

## Method
1. divide and conquer + traverse

Key point: 定义函数返回值：返回以当前NODE为根的最大序列长度， 分治得到左右子树长度后，求当前最大长度，同时看是否要更新全局变量值

## Solution
1.1 Divide and Conquer + traversal
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
     * @return: the length of the longest consecutive sequence path
     */
    int longestConsecutive(TreeNode * root) {
        // write your code here
        if (!root) {
            return 0;
        }
        longest = 0;
        helper(root);
        return longest;
    }
    
    // return current node as root's longest length
    int helper(TreeNode* root) {
        if (!root) {
            return 0;
        }        

        int subtreelongest = 1;
        
        int left = helper(root->left);
        int right = helper(root->right);

        if (root->left) {
            if (root->val + 1 == root->left->val) {
                subtreelongest = max(left + 1, subtreelongest);
            }
        }
        if (root->right) {
            if (root->val + 1 == root->right->val) {
                subtreelongest = max(right + 1, subtreelongest);
            }
        }

        longest = max(longest, subtreelongest);
        
        return subtreelongest;
        
    }
private:
    int longest;
};
~~~

## Similar problems
[Binary Tree Longest Consecutive Sequence II](https://www.lintcode.com/problem/binary-tree-longest-consecutive-sequence-ii/)
[Binary Tree Longest Consecutive Sequence II](https://www.lintcode.com/problem/binary-tree-longest-consecutive-sequence-iii/)


## Tags
Binary Tree Traversal + Divide and Conquer
