# 376. Binary Tree Path Sum

## Description
~~~
Given a binary tree, find all paths that sum of the nodes in the path equals to a given number target.
A valid path is from root node to any of the leaf nodes.

Example
Given a binary tree, and target = 5:
     1
    / \
   2   4
  / \
 2   3
return
[
  [1, 2, 2],
  [1, 4]
]


~~~

## Link
[lintcode](https://www.lintcode.com/problem/binary-tree-path-sum)

## Method
1. divide and conquer + traverse

Key point: 定义函数返回值：返回以当前NODE为根所开始（包含NODE)的最大序列长度， 分治得到左右子树长度后，求当前最大长度，同时看是否要更新全局变量值

## Solution
1.1 Divide and Conquer + traversal
~~~
/**
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 */


public class Solution {
    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    public List<List<Integer>> binaryTreePathSum(TreeNode root, int target) {
        // write your code here
    }
}
~~~

## Similar problems
[Binary Tree Path Sum II](https://www.lintcode.com/problem/binary-tree-path-sum-ii)
[Binary Tree Path Sum III](https://www.lintcode.com/problem/binary-tree-path-sum-iii)


## Tags
Binary Tree Traversal + Divide and Conquer
