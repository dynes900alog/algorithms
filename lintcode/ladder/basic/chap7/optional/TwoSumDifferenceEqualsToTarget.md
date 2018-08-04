# 610. Two Sum - Difference equals to target

## Description

Given an array of integers, find two numbers that their difference equals to a target value.
where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are NOT zero-based.

```
Notice
It's guaranteed there is only one available solution
```
**Example**
```
Given nums = [2, 7, 15, 24], target = 5
return [1, 2] (7 - 2 = 5)

```

## Link
[lintcode](https://lintcode.com/problem/two-sum-difference-equals-to-target/)

## Method
* Two Pointers

* Hash Table  

## Solution
1.1 Two Pointers
~~~
struct Node {
    int value;
    int index;
    Node(int _value, int _index) : value(_value), index(_index) {}
};

bool Compare(const Node& node1, constNode& node2) {
    return (node1.value < node2.value);
}

class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    vector<int> twoSum7(vector<int> &numbers, int target) {
        // write your code here
        int length = numbers.size();
        if (length <= 1) {
            return -1;
        }
        
        vector<Node> nums;
        for (int i = 0; i < length; i++) {
            nums.push_back(Node(numbers[i], i+1));
        }

        sort(nums.begin(), nums.end(), Compare());

        int j = 0;
        // note: here time complexity is only O(2n), not O(n^2). becasue j is increased based on previous value to hit length eventually
        for (int i = 0; i < length; i++) {
            if (j == i) {
                j++;
            }
            while(j < length && (nums[j] - nums[i] < target)) {
                j++;
            }
            if (j > i && (nums[j] - nums[i] == target)) {
                result.push_back(min(left.index, right.index));
                result.push_back(max(right.index, left.index));
                return result;
            }
        }

        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
};
~~~

1.2 Hash Map
~~~
class Solution {
public:
    /*
     * @param nums an array of Integer
     * @param target an integer
     * @return [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum7(vector<int> &nums, int target) {
        // write your code here
        vector<int> result(2);
        unordered_map<int, int> table;
        if (target < 0) {
            target = -target;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (table.find(nums[i] + target) != table.end()) {
                result[0] = table[nums[i] + target];
                result[1] = i + 1;
                break;
            }
            else if (table.find(nums[i] - target) != table.end()) {
                result[0] = table[nums[i] - target];
                result[1] = i + 1;
                break;
            }
            else {
                table[nums[i]] = i + 1;
            }
        }
        
        return result;
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