# 614. Binary Tree Longest Consecutive Sequence II

## Description
~~~
Given a binary tree, find the length of the longest consecutive sequence path.
The path could be start and end at any node in the tree


Example
 1
   / \
  2   0
 /
3
Return 4 // 0-1-2-3


~~~

## Link
[lintcode](https://www.lintcode.com/problem/binary-tree-longest-consecutive-sequence-ii/)

## Method
1. divide and conquer

Key point: 用分治法。
我们用ResultType来记录从某一个点往下走的时候递增的最大路径和递减的最大路径，以及一个全局的最长路径。
在某一点，全局的最长路径就是：
1：左子树中遇到的最长路径
2：右子树中遇到的最长路径
3：通过当前点的最长路径
这三者的最大值。

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
class ResultType {
public:
    int maxSeq;
    int upSeq;
    int downSeq;
    ResultType(int max, int up, int down): maxSeq(max), upSeq(up), downSeq(down) {}
};

class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    int longestConsecutive2(TreeNode * root) {
        // write your code here
        if (!root) {
            return 0;
        }
        ResultType result = helper(root);
        return result.maxSeq;
    }
    
    // return current node as root's longest length
    ResultType helper(TreeNode* root) {
        if (!root) {
            return ResultType(0,0,0);
        }

        int upSeq = 0;
        int downSeq = 0;
        
        ResultType left = helper(root->left);
        ResultType right = helper(root->right);

        if (root->left) {
            if (root->val + 1 == root->left->val) {
                downSeq = max(downSeq, left.downSeq + 1);
            }
            if (root->val == root->left->val + 1) {
                upSeq = max(upSeq, left.upSeq + 1);
            }
        }
        
        if (root->right) {
            if (root->val + 1 == root->right->val) {
                downSeq = max(downSeq, right.downSeq + 1);
            }
            if (root->val == root->right->val + 1) {
                upSeq = max(upSeq, right.upSeq + 1);
            }
        }

        // connect left, right and root
        int maxSeq = max(left.maxSeq, right.maxSeq);
        
        // Note: upSeq/downSeq is 0 if it's leaf node: upSeq/downSeq value is the total number of nodes exclude current root node
        maxSeq = max(maxSeq, upSeq + downSeq + 1);
        
        return ResultType(maxSeq, upSeq, downSeq);
    }
};
~~~

## Similar problems
[Binary Tree Longest Consecutive Sequence I](https://www.lintcode.com/problem/binary-tree-longest-consecutive-sequence/)
[Binary Tree Longest Consecutive Sequence III](https://www.lintcode.com/problem/binary-tree-longest-consecutive-sequence-iii/)


## Tags
Binary Tree Traversal + Divide and Conquer
