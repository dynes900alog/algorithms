# 103. Linked List Cycle II

## Description
~~~
Given a linked list, return the node where the cycle begins.

If there is no cycle, return null.

~~~

**Example**
```
Given -21->10->4->5, tail connects to node index 1，return 10
```

## Link
[lintcode](https://www.lintcode.com/problem/linked-list-cycle-ii/)

## Method
* Use slow/fast pointer to detect cycle and meeting positiion  
Key point: calculate how many nodes in the loop  

## Solution
1.1 
~~~
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param head: The first node of linked list.
     * @return: The node where the cycle begins. if there is no cycle, return null
     */
    ListNode * detectCycle(ListNode * head) {
        // write your code here
        // get the meeting position
        ListNode* pMeetNode = MeetNode(head);
        
        if (pMeetNode == NULL) {
            return NULL;
        }
        
        // how many nodes in the loop
        int nodesInLoop = 1;
        ListNode* pNode1 = pMeetNode;
        while(pNode1->next != pMeetNode) {
            nodesInLoop++;
            pNode1 = pNode1->next;
        }
        
        // start from head to go forward nodesInLoop steps (L = nodeNotInLoop + nodesInLoop)
        pNode1 = head;
        for(int i = 0; i < nodesInLoop; i++) {
            pNode1 = pNode1->next; 
        }

        // cycle point is where P1/P2 meet again
        ListNode* pNode2 = head;
        while(pNode1 != pNode2) {
            pNode1 = pNode1->next;
            pNode2 = pNode2->next;
        }
        
        return pNode1;
    }
    
    
    ListNode* MeetNode(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        
        ListNode* pSlow = head->next;
        if (pSlow == NULL) {
            return NULL;
        }
        
        ListNode* pFast = pSlow->next;
        
        while(pFast) {
            if (pSlow == pFast) {
                return pSlow;
            }
            
            pSlow = pSlow->next;
            
            pFast = pFast->next;
            if (pFast) {
                pFast = pFast->next;
            }
        }

        return NULL;
    }
};
~~~

## Similar problems
[Linked List Cycle](https://www.lintcode.com/problem/linked-list-cycle/)  
## Tags
Linked List & Array 
