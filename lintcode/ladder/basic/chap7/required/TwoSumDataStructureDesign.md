# 507. Two Sum III - Data structure design

## Description

Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

**Example**
```
add(1); add(3); add(5);
find(4) // return true
find(7) // return false
```

**Challenge**  
Either of the following solutions are acceptable:

* O(n) Space, O(nlogn) Time
* O(n) Space, O(n) Time

## Link
[lintcode](https://lintcode.com/problem/two-sum-iii-data-structure-design/)

## Method
* Hash Table
  * key point : Hash Table to save <value, count>

## Solution
1.1 Hash Table
~~~
class TwoSum {
private:
    // key = number, value = count
    unordered_map<int, int> hashtable;    
public:
    /*
     * @param number: An integer
     * @return: nothing
     */
    void add(int number) {
        // write your code here
        hashtable[number]++;
    }

    /*
     * @param value: An integer
     * @return: Find if there exists any pair of numbers which sum is equal to the value.
     */
    bool find(int value) {
        // write your code here
        for(unordered_map<int, int>::iterator it = hashtable.begin(); it != hashtable.end(); it++) {
            int res = value - it->first;
            if (hashtable.find(res) == hashtable.end()) {
                continue;
            }
            
            if (res != it->first || 
                (res == it->first && (it->second > 1))) {
                    return true;
            }
        }

        return false;
    }
};
~~~
## Similar problems
[Two Sum](https://lintcode.com/problem/two-sum/)  
[Two Sum II - Input array is sorted](https://lintcode.com/problem/two-sum-input-array-is-sorted/)   
[Two Sum II - Less than or equal to target](https://lintcode.com/problem/two-sum-less-than-or-equal-to-target/)   
[Two Sum - Unique pairs](https://lintcode.com/problem/two-sum-unique-pairs/)  
[Two Sum - Closest to target](https://lintcode.com/problem/two-sum-closest-to-target/)  
[Two Sum - Difference equals to target](https://lintcode.com/problem/two-sum-difference-equals-to-target/)  
[Two Sum - Greater than target](https://lintcode.com/problem/two-sum-greater-than-target/)  
[Two Sum III- Data structure design](https://lintcode.com/problem/two-sum-data-structure-design/)  
[3Sum](https://lintcode.com/problem/3sum/)

## Tags
Two Pointers  
Hash Table