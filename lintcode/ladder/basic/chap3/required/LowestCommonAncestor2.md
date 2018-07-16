# 474. Lowest Common Ancestor of a Binary Tree II

## Description
~~~
Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.

The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.

The node has an extra attribute parent which point to the father of itself. The root's parent is null.


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
[lintcode](https://www.lintcode.com/problem/lowest-common-ancestor-ii)

## Method
1. 因为加了个parent指针，可以自底而上找到每个node到root的路径，然后分别找到两个node的从root出发的path开始出现不同的前一个node，即是LCA。
Key point:  

## Solution
1.1 Divide and Conquer 
~~~
/**
 * Definition of ParentTreeNode:
 * class ParentTreeNode {
 * public:
 *     int val;
 *     ParentTreeNode *parent, *left, *right;
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of the tree
     * @param A, B: Two node in the tree
     * @return: The lowest common ancestor of A and B
     */
    ParentTreeNode *lowestCommonAncestorII(ParentTreeNode *root,
                                           ParentTreeNode *A,
                                           ParentTreeNode *B) {
        ParentTreeNode* result = NULL;
        if (root == NULL) {
            return result;
        }

        vector<ParentTreeNode*> resultA = findPath(A);
        vector<ParentTreeNode*> resultB = findPath(B);
        int indexA = resultA.size() - 1;
        int indexB = resultB.size() - 1;

        // find the intersection: the first node not equal
        while(indexA > 0 && indexB > 0) {
            if (resultA[indexA] != resultB[indexB]) {
                break;
            }
            result = resultA[indexA];
            indexA--; indexB--;
        }

        return result;        
    }

    vector<ParentTreeNode*> findPath(ParentTreeNode *root) {
        vector<ParentTreeNode *> result;
        while(root->parent) {
            result.push_back(root);
            root = root->parent;
        }

        return result;
    }

};
~~~

## Similar problems
[Lowest Common Ancestor](https://www.lintcode.com/problem/lowest-common-ancestor-of-a-binary-tree/)


## Tags
Binary Tree Traversal
