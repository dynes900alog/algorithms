# 105. Copy List with Random Pointer

## Description
~~~
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
~~~

**Challenge**
```
Could you solve it with O(1) space?
```

## Link
[lintcode](https://www.lintcode.com/problem/copy-list-with-random-pointer/)

## Method
1. Clone singly linked list with 1-to-1 old/new nodes mapping 
Key point: It's easy to clone singly linked list. How to maintain the mapping relation ship between original and new node?


## Solution
1.1 
~~~
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        RandomListNode* newHead = NULL ;
        if (head == NULL) {
            return newHead;
        }
        
        // clone all nodes and setup map (1->1`->2->2`->...->n->n`, without touching random pointer)
        CloneNodes(head);

       // setup random pointer first (becasue random pointer can point back to previous node)
       ConnectRandomNodes(head);
       
       // setup next pointer
       newHead = ReConnectNodes(head);
       
       return newHead;
    }
    
    void CloneNodes(RandomListNode* pHead) {
        RandomListNode* pNode = pHead;
        while(pNode) {
            RandomListNode* pCloneNode = new RandomListNode(pNode->label);
            pCloneNode->next = pNode->next;
            pCloneNode->random = NULL;
            
            pNode->next = pCloneNode;
            pNode = pCloneNode->next;            
        }
    }
    
    void ConnectRandomNodes(RandomListNode* pHead) {
        RandomListNode* pNode = pHead;
        while(pNode) {
            RandomListNode* pCloneNode = pNode->next;
            if (pNode->random) {
                pCloneNode->random = pNode->random->next;
            }
            pNode = pCloneNode->next;            
        }
    }

    RandomListNode* ReConnectNodes(RandomListNode* pHead) {
        RandomListNode* pNode = pHead;
        RandomListNode* pCloneHead = NULL;
        
        if (pHead != NULL) {
            pCloneHead = pHead->next;
        }

        while(pNode) {
            RandomListNode* pCloneNode = pNode->next;
            RandomListNode* pNextNode = pCloneNode->next;
            
            if (pNextNode) {
                pCloneNode->next = pNextNode->next;
            }
            
            pNode->next = pNextNode;
            pNode = pNextNode;            
        }
        
        return pCloneHead;
    }
    
};
~~~

## Similar problems
[Clone Binary Tree](https://www.lintcode.com/problem/clone-binary-tree/)  
[Clone Graph](https://www.lintcode.com/problem/clone-graph/)  

## Tags
Linked List & Array 
