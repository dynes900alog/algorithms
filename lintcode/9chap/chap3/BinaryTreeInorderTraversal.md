# 67. Binary Tree Inorder Traversal

## Description
~~~
Given a binary tree, return the inorder traversal of its nodes' values.

Example
Given binary tree {1,#,2,3},

   1  
    \  
     2  
    /  
   3  
return [1,3,2].

Challenge
Can you do it without recursion?
~~~
Example
Given [1, 2, 2, 4, 5, 5].
For target = 2, return 1 or 2.
For target = 5, return 4 or 5.
For target = 6, return -1.

## Link
[lintcode](https://www.lintcode.com/problem/binary-tree-inorder-traversal/description/)

## Method
1. recursive traversal is direct 
2. iterative more complicated

Key point:  使用辅助栈改写递归程序，中序遍历没有前序遍历好写，其中之一就在于入栈出栈的顺序和限制规则。我们采用「左根右」的访问顺序可知主要由如下四步构成。

1. 首先需要一直对左子树迭代并将非空节点入栈
2. 节点指针为空后不再入栈
3. 当前节点为空时进行出栈操作，并访问栈顶节点
4. 将当前指针p用其右子节点替代
步骤2,3,4对应「左根右」的遍历结构，只是此时的步骤2取的左值为空。

## Solution
1.1 recursive
~~~
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };  
 */

class Solution {

public:

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }

private:

    void helper(TreeNode *root, vector<int> &ret) {
        if (root != NULL) {
            helper(root->left, ret);
            ret.push_back(root->val);
            helper(root->right, ret);
        }
    }
};

1.2 iterative

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };  
 */

class Solution {

public:

    /**    
     * @param root: A Tree
     * @return: Inorder in ArrayList which contains node values.
     */
    vector<int> inorderTraversal(TreeNode * root) {
        // write your code here
        vector<int> result;
        stack<TreeNode*> s;
        
        /*
        if (root == NULL {
            return result;    
        }
        */
        
        TreeNode* node = root;
        
        while(!s.empty() || node) {
            if (node) {
                s.push(node);
                node = node->left;
            }
            else {
                node = s.top();
                s.pop();
                result.push_back(node->val);
                node = node->right;
            }
        }
        
        return result;
    }
};
~~~

## Similar problems
x

## Tags
Binary Tree
