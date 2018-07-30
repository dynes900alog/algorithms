# 139. Subarray Sum Closest

## Description
~~~
Given an integer array, find a subarray with sum closest to zero. Return the indexes of the first number and last number.

~~~

**Example**
```
Given [-3, 1, 1, -3, 5], return [0, 2], [1, 3], [1, 1], [2, 2] or [0, 4].
```
**Challenge**

O(nlogn) time

## Link
[lintcode](https://www.lintcode.com/problem/subarray-sum-closest/)

## Method
* Get all PrefixSum[i]/Index pair and sort them based on sum, find the closest between neighbors
    * Key point: Sort on sums, and note the override of operator "<" for std::sort()

## Solution
1.1 
~~~
class Solution {

public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    struct Node {
        int val;
        int index;
        Node(int _val, int _index): val(_val), index(_index) {}
        bool operator<(const Node &node) const {
            return (val < node.val || (val == node.val && index < node.index));
        }    
    };
    
    vector<int> subarraySumClosest(vector<int> &nums) {
        // write your code here
        // idea: get all PrefixSum[]/Index and sort 
        vector<int> result(2);
        int size = nums.size();
        if (size <= 0) {
            return result;
        }
        
        vector<Node> PrefixSum;

        int sum = 0;
        for(int i = 0; i < size; i++) {
            sum += nums[i];
            PrefixSum.push_back(Node(sum, i)); 
        }
        
        sort(PrefixSum.begin(), PrefixSum.end());
        
        int minDelta = INT_MAX;
        
        for(int i = 1; i <= size; i++) {
            int delta = abs(PrefixSum[i].val - PrefixSum[i-1].val);
            if (delta < minDelta) {
                result[0] = min(PrefixSum[i].index, PrefixSum[i-1].index) + 1;
                result[1] = max(PrefixSum[i].index, PrefixSum[i-1].index);
                minDelta = delta;
            }
        }
        
        return result;        
    }
};
~~~

## Similar problems
[Subarray Sum II](https://www.lintcode.com/problem/subarray-sum-ii/)  

## Tags
Array (PrefixSum[])
