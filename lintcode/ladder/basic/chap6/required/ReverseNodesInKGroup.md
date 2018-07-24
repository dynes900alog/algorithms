# 450. Reverse Nodes in K-Group

## Description
~~~
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.
Only constant memory is allowed.
~~~

**Example**
```
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
```

## Link
[lintcode](https://lintcode.com/problem/reverse-nodes-in-k-group/)

## Method
1. Reverse K nodes each round:  
head->n(1)->n(2)->n(3)->......->n(k-1)->n(k)->n(k+1)  
========>   
head->n(k)->n(k-1)->......->n(3)->n(2)->n(1)->n(k+1)  
Key point: Reverse Linked List nodes by number - how to use dummy node to avoid head node change?  
##1. dummy node as the extra head to avoid head changes during manipulating (dummy.next is always the new head)  
##2. subfunction signature: return the next part of the dummy head node so we can continue doing reverse next k : n(1), which is original head->next


## Solution
1.1 
~~~
/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: a ListNode
     * @param k: An integer
     * @return: a ListNode
     */
    ListNode * reverseKGroup(ListNode * head, int k) {
        // write your code here
        ListNode dummyNode(0);
        dummyNode.next = head;
        head = &dummyNode;
        
        while(head) {
            head = reverseK(head, k);
        }
     
        return dummyNode.next;;
    }
    
    // n0->n1->n2->n3...->nk->nk+1   ------> n0->nk->nk-1->...->n1->nk+1  
    // return n1 as the next dummy head
    ListNode* reverseK(ListNode* head, int k) {
        // check if there is enough nodes
        int cnt = 0;
        ListNode* node = head->next;
        for(int i = 0; i < k; i++) {
            if (node == NULL) {
                return NULL;
            }
            node = node->next;
        }

        ListNode* previous = NULL;
        ListNode* current = head->next;
        ListNode* n1 = head->next;
        
        while(k > 0) {
            ListNode* next = current->next;
            current->next = previous;
            previous = current;
            current = next;
            k--;
        }
        
        // update head, tail 
        head->next = previous;
        n1->next = node; // or current
         
        return n1;
    }

};
~~~

## Similar problems
[Reverse Linked List](https://lintcode.com/problem/reverse-linked-list/)  
[Reverse Linked List](https://lintcode.com/problem/reverse-linked-list-ii/)  
[Swap Nodes in Paris](https://lintcode.com/problem/swap-nodes-in-pairs/)  
## Tags
Linked List & Array 
