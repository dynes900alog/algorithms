# 614. Binary Tree Longest Consecutive Sequence III

## Description
~~~
It's follow up problem for Binary Tree Longest Consecutive Sequence II

Given a k-ary tree, find the length of the longest consecutive sequence path.
The path could be start and end at any node in the tree



Example
 An example of test data: k-ary tree 5<6<7<>,5<>,8<>>,4<3<>,5<>,3<>>>, denote the following structure:


     5
   /   \
  6     4
 /|\   /|\
7 5 8 3 5 3

Return 5, // 3-4-5-6-7

~~~

## Link
[lintcode](https://www.lintcode.com/problem/binary-tree-longest-consecutive-sequence-iii/)

## Method
1. divide and conquer

Key point: 用分治法。
和Binary Tree Longest Consecutive Sequence II一样的做法。
II只要check一下left和right。
这题因为有多个子节点，所以要用一个循环来check所有。

## Solution
1.1 Divide and Conquer
~~~
/**

 * Definition for a multi tree node.

 * struct MultiTreeNode {

 *     int val;

 *     vector<TreeNode*> children;

 *     MultiTreeNode(int x) : val(x) {}

 * };

 */
class ResultType {
public:
    int globalMax;
    int maxUp;    // local max increase sequence based on current node
    int maxDown;  // local max decrease sequence based on current node
    ResultType(int max, int up, int down): globalMax(max), maxUp(up), maxDown(down) {}
};

class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    int longestConsecutive3(MultiTreeNode * root) {
        // write your code here
        if (!root) {
            return 0;
        }
        ResultType result = helper(root);
        return result.globalMax;
    }
    
    // return current node as root's longest length
    ResultType helper(MultiTreeNode* root) {
        if (!root) {
            return ResultType(0,0,0);
        }

        int up = 0;
        int down = 0;
        
        for(MultiTreeNode* child : root->children) {
            if (!child) {
                continue;
            }

            ResultType childResult = helper(child);

            if (child->val + 1 == root->val) {
                up = max(up, childResult.maxUp + 1);
            }
            if (child->val - 1 == root->val) {
                down = max(down, childResult.maxDown + 1);
            }
            maxSeq = max(maxSeq, childResult.globalMax);
        }

        // connect left, right and root
        maxSeq = max(maxSeq, up + down + 1);
        // Note: upSeq/downSeq is 0 if it's leaf node: upSeq/downSeq value is the total number of nodes exclude current root node
        
        return ResultType(maxSeq, up, down);
    }
};
~~~

## Similar problems
[Binary Tree Longest Consecutive Sequence I](https://www.lintcode.com/problem/binary-tree-longest-consecutive-sequence/)  
[Binary Tree Longest Consecutive Sequence II](https://www.lintcode.com/problem/binary-tree-longest-consecutive-sequence-ii/)


## Tags
Binary Tree Traversal + Divide and Conquer
