# 56. Two Sum

## Description

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are zero-based.
```
You may assume that each input would have exactly one solution
```

**Example**
```
numbers=[2, 7, 11, 15], target=9

return [0, 1]
```

**Challenge**  
Either of the following solutions are acceptable:

* O(n) Space, O(nlogn) Time
* O(n) Space, O(n) Time

## Link
[lintcode](https://lintcode.com/problem/two-sum/)

## Method
* Hash Table
  * key point : Hash when doing traverse, assume no duplicated results
* Sort and serach by 2 pointers

## Solution
1.1 Two Pointers
~~~
class Solution {
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1, index2] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        // write your code here
        // hash table to save all value/index pairs
        unordered_map<int, int> hashtable;
        vector<int> result;
        
        int length = numbers.size();
        
        for(int i = 0; i < length;  i++) {
            int res = target - numbers[i];
                
            if (hashtable.find(res) != hashtable.end()) {
                result.push_back(hashtable[res]);
                result.push_back(i);
                return result;
            }
            hashtable[numbers[i]] = i;    
        }

        // no rresult
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
};
~~~

1.2 Two Pointers
~~~
struct Node{
    int value;
    int index;
    Node(int _value, int _index) : value(_value), index(_index) {}
    bool operator < (const Node & e) {
        return (value < e.value);
    }
};

/* another way to define comparing function instead of override "<":
   struct Node {
        int val;
        int index;
        Node(int pVal, int pIndex) : val(pVal), index(pIndex) {
            
        }
    };
    
    static bool compare(const Node &node1, const Node &node2) {
        return node1.val < node2.val;
    }
    // the way to call "sort()"
    // sort(nums.begin(), nums.end(), compare);
*/

class Solution {
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1, index2] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        // write your code here
        // hash table to save all value/index pairs
        vector<int> result;
        
        int length = numbers.size();
        
        // save as index/value pairs
        vector<Node> nums;

        for(int i = 0; i < length; i++) {
            Node e(numbers[i], i);
            nums.push_back(e);   
        }
        
        sort(nums.begin(), nums.end());
        
        int i = 0, j = length -1;
        while (i < j) {
            int sum = nums[i].value + nums[j].value;
            if (sum == target) {
                result.push_back(min(nums[i].index, nums[j].index));
                result.push_back(max(nums[i].index, nums[j].index));
                return result;
            }
            else if (sum < target) {
                i++;
            }
            else {
                j--;
            }
        }

        // not found        
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
};
~~~
## Similar problems
[Two Sum - Closest to target](https://lintcode.com/problem/two-sum-closest-to-target/)  
[Two Sum - Unique pairs](https://lintcode.com/problem/two-sum-unique-pairs/)  
[Two Sum II - Input array is sorted](https://lintcode.com/problem/two-sum-input-array-is-sorted/)   
[Two Sum III- Data structure design](https://lintcode.com/problem/two-sum-data-structure-design/)  
[3Sum](https://lintcode.com/problem/3sum/)

## Tags
Two Pointers  
Hash