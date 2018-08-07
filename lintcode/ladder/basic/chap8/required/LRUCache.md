# 134. LRU Cache

## Description

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
```
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.

set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
```

## Link
[lintcode](https://www.lintcode.com/problem/lru-cache/)

## Method
* Doubly Linked List (keep LRU) + Hash Talbe(key/Node mapping)
  * Doubly Linked List: LRU node in head, MRU in tail (or reverse). Note to use dummy head/tail to avoid updating head/tail
* Singly Linked List + Hash Table
  * Singly Linked List (LRU) + Hash Table (key/Previous Node). Note to use previous Node here since we need to move current node to tail/head and it has to update its previous node.

## Solution
1.1 Doubly Linked List + Hash
~~~
class Node {
public:
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int _key, int _value) {
        key = _key;
        value = _value;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache {
    private:
    int capacity;
    Node* head; // head: LRU
    Node* tail; // tail: MRU
    unordered_map<int, Node*> hashtable;
public:
    /*
    * @param capacity: An integer
    */
    LRUCache(int capacity) {
        // do intialization if necessary
        this->capacity = capacity;
        // dummy head/tail
        this->head = new Node(0, 0);
        this->tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        // write your code here
        if (hashtable.find(key) == hashtable.end()) {
            return -1;
        }    

        Node* node = hashtable[key];
        // move the node to the tail (head/tail not NULL)
        node->prev->next = node->next;
        node->next->prev = node->prev;

        moveToTail(node);
        return node->value;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        // write your code here
        // if key exisits, update by accessing it
        if (get(key) != -1) {
            // get(key) automatically move key node to the front
            Node* node = hashtable[key];
            node->value = value;
            return;
        }

        // if full, invalidate the head node
        if (hashtable.size()  == capacity) {
            hashtable.erase(head->next->key);

            Node* temp = head->next;
            head->next = head->next->next;
            head->next->prev = head;
            delete temp;
        }

        Node* node = new Node(key, value);
        hashtable[key] = node;
        moveToTail(node);
    }

    void moveToTail(Node* node) {
        // assume node is in the list
        node->prev = tail->prev;
        tail->prev = node;
        node->prev->next = node;
        node->next = tail;
    }
};
~~~

1.2 Singly Linked List + HashMap
~~~
// Singly Linked List solution: hashtable[key] = previous node
struct Node {
    int value;
    int key;
    Node* next;
    Node(int _key, int _value) {
        key = _key;
        value = _value;
        next = NULL;
    }
};

class LRUCache {
private:
    int capacity;
    // LRU is on head, MRU is on tail (Most rcent)
    Node* head;
    Node* tail;
    //
    unordered_map<int, Node*> hashtable;
    
public:
    /*
    * @param capacity: An integer
    */
    LRUCache(int capacity) {
        // do intialization if necessary
        this->capacity = capacity;
        //dummy node
        head = new Node(0, 0);
        tail = head;
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        // write your code here
        if (hashtable.find(key) == hashtable.end()) {
            return -1;
        }
        
        Node* previous = hashtable[key];
        Node* current = previous->next;
        
        move_to_tail(previous);

        return current->value;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        // write your code here
        if (get(key) != -1) {
            Node* node = hashtable[key];
            node->next->value = value;
            move_to_tail(node);
            return;
        }
        
        if (hashtable.size() == capacity) {
            // remove LRU head Node
            Node* current = head->next;
            hashtable.erase(current->key);
            head->next = current->next;
            if (current->next) {
                hashtable[current->next->key] = head;
            }
            delete current;
        }
        
        // insert to tail
        Node* node = new Node(key, value);
        hashtable[key] = tail;
        tail->next = node;
        tail = node;
    }
    
    // most recently used is on tail
    void move_to_tail(Node *previous) {
        // Node to move
        Node* current = previous->next;
        
        if (current == tail) {
            return;    
        }
        
        if (current->next) {
            hashtable[current->next->key] = previous;
        }
        
        previous->next = current->next;
        current->next = NULL;
        tail->next = current;
        hashtable[current->key] = tail;
        tail = current;
    }
    
};
~~~

## Similar problems
[Consistent Hashing](https://www.lintcode.com/problem/consistent-hashing/)  
[LFU Cache (Least Frequently Used) ](https://www.lintcode.com/problem/lfu-cache/)  

## Tags
Hash & Heap (Data Structure)