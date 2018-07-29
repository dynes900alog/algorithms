# 98. Sort List

## Description
~~~
Sort a linked list in O(n log n) time using constant space complexity.

~~~

**Example**
```
Given 1->3->2->null, sort it to 1->2->3->null.
```
**Challenge**

Solve it by merge sort & quick sort separately.

## Link
[lintcode](https://www.lintcode.com/problem/sort-list/)

## Method
* Merge Sort: Use slow/fast pointer to get middle positiion  
Time:O(nlongn)  
Space: O(1) for linked list (Merge - no need with extra space for linked list; for array, it's O(n))
* Quick Sort: Partition + Connect (use dummy node) 
    * key point: partion 2-way or 3-way, not swap nodes as array because missing previous node info
Time: O(nlogn)  
Space: O(1)
* Heap Sort - not pratical for linked list (lef, right child postion 2*n, 2*n+1)
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
     * @param head: The head of linked list.
     * @return: You should return the head of the sorted linked list, using constant space complexity.
     */
    ListNode * sortList(ListNode * head) {
        // write your code here
        return MergeSort(head);
    }
    
    
    ListNode* MergeSort(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        // body
        ListNode* midNode = FindMiddle(head);

        // sequence: the second half first to save one variable space (modNode->next != NULL)
        ListNode* headNode2 = MergeSort(midNode->next);
        
        midNode->next = NULL;
        ListNode* headNode1 = MergeSort(head);
        
        return MergeList(headNode1, headNode2);
    }
    
    // find middle node
    ListNode* FindMiddle(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }    
        
        ListNode* slow = head;
        ListNode* fast = slow->next;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    
    // Merge two lists and return new head
    ListNode* MergeList(ListNode* head1, ListNode* head2) {
        ListNode dummyNode;
        ListNode* tail = &dummyNode;

        while(head1 && head2) {
            if (head1->val < head2->val) {
                tail->next = head1;
                head1 = head1->next;
            }
            else {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }
        
        if (head1) {
            tail->next = head1;
        }
        
        if (head2) {
            tail->next = head2;
        }
        
        return dummyNode.next;
    }
};
~~~

1.2 Quick Sort (2-way)
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
class PairNode {
public:
    ListNode* first;
    ListNode* second;
    PairNode(ListNode* node1, ListNode* node2) : first(node1), second(node2) {}
};

class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @return: You should return the head of the sorted linked list, using constant space complexity.
     */
    ListNode * sortList(ListNode * head) {
        // write your code here
        // return MergeSort(head);
        return QuickSort(head);
    }
    
    
    ListNode* QuickSort(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        // body part
        ListNode* midNode = FindMiddle(head);
        
        PairNode pair = Partition(head, midNode->val);
        
        ListNode* head1 = QuickSort(pair.first);
        ListNode* head2 = QuickSort(pair.second);
        
        ListNode* tail = GetTail(head1);
        tail->next = head2;
        
        return head1;
    }

    PairNode Partition(ListNode* head, int val) {
        ListNode dummyLeft(0);
        ListNode dummyRight(0);
        ListNode dummyEqual(0);
        
        ListNode* leftTail = &dummyLeft;
        ListNode* rightTail = &dummyRight;
        ListNode* equalTail = &dummyEqual;
        
        while(head) {
            if (head->val < val) {
                leftTail->next = head;
                leftTail = leftTail->next;
            }
            else if (head->val > val) {
                rightTail->next = head;
                rightTail = rightTail->next;
            }
            else {
                equalTail->next = head;
                equalTail = equalTail->next;
            }
            
            head = head->next;
        }
        
        leftTail->next = NULL;
        equalTail->next = NULL;
        rightTail->next = NULL;

        // connect "left----equal----right" if any part of left/right is empty        
        if (dummyLeft.next == NULL && dummyRight.next == NULL) {
            ListNode* midNode = FindMiddle(dummyEqual.next);
            dummyLeft.next = dummyEqual.next;
            dummyRight.next = midNode->next;
            midNode->next = NULL;
        }
        else if (dummyLeft.next == NULL) {
            dummyLeft.next = dummyEqual.next;
        }
        // right+equal
        else {
            rightTail->next = dummyEqual.next;
            /* Or
            //equalTail->next = dummyRight.next;
            //dummyRight.next = dummyEqual.next;
            */
        }
        
        return PairNode(dummyLeft.next, dummyRight.next);
    }
    
    ListNode* GetTail(ListNode *head) {
        while(head->next) {
            head = head->next;    
        }
        return head;
    }
};
~~~

1.3 Quick Sort (3 way, not verified)
~~~
// version 2: Quick Sort 1
public class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        
        ListNode mid = findMedian(head); // O(n)
        
        ListNode leftDummy = new ListNode(0), leftTail = leftDummy;
        ListNode rightDummy = new ListNode(0), rightTail = rightDummy;
        ListNode middleDummy = new ListNode(0), middleTail = middleDummy;
        while (head != null) {
            if (head.val < mid.val) {
                leftTail.next = head;
                leftTail = head;
            } else if (head.val > mid.val) {
                rightTail.next = head;
                rightTail = head;
            } else {
                middleTail.next = head;
                middleTail = head;
            }
            head = head.next;
        }
        
        leftTail.next = null;
        middleTail.next = null;
        rightTail.next = null;
        
        ListNode left = sortList(leftDummy.next);
        ListNode right = sortList(rightDummy.next);
        
        return concat(left, middleDummy.next, right);
    }
    
    private ListNode findMedian(ListNode head) {
        ListNode slow = head, fast = head.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
    
    private ListNode concat(ListNode left, ListNode middle, ListNode right) {
        ListNode dummy = new ListNode(0), tail = dummy;
        
        tail.next = left; tail = getTail(tail);
        tail.next = middle; tail = getTail(tail);
        tail.next = right; tail = getTail(tail);
        return dummy.next;
    }
    
    private ListNode getTail(ListNode head) {
        if (head == null) {
           return null;
        } 
       
        while (head.next != null) {
            head = head.next;
        }
        return head;
    }
}
~~~
## Similar problems
[Insertion Sort List](https://www.lintcode.com/problem/insertion-sort-list/)  
## Tags
Linked List & Array 
