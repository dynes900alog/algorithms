# 138. Subarray Sum

## Description

Given an integer array, find a subarray where the sum of numbers is zero. Your code should return the index of the first number and the index of the last number.
```
There is at least one subarray that it's sum equals to zero.
```

**Example**
```
Given [-3, 1, 2, -3, 4], return [0, 2] or [1, 3].
```
**Challenge**

Can you do it in time complexity O(n)?

## Link
[lintcode](https://www.lintcode.com/problem/subarray-sum)

## Method
* PrefixSum  
    * Key point: if sum[0, i] == sum[0,j], we have "sum[i+1,j] == 0";use hash table to save all sum/index 
## Solution
1.1 
~~~
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int> &nums) {
        // write your code here
        // idea: sum[0, current_index] == sum[0, previous_index], means we have one solution "sum[previous+1, current] == 0"
        int size = nums.size();
        vector<int> result;
        
        if (size <= 0) {
            return result;
        }
        
        // hashmap to save <sum[0,current], current>
        unordered_map<int, int> hashtable;

        int sum = 0;
        hashtable[sum] = -1;
        
        for(int i = 0; i < size; i++) {
            sum += nums[i];
            if (hashtable.find(sum) != hashtable.end()) {
                int previous = hashtable[sum];
                result.push_back(previous+1);
                result.push_back(i);
            }
            else {
                hashtable[sum] = i;
            }
        }
        
        return result;
    }
};
~~~

## Similar problems
[Subarray Sum Closest](https://www.lintcode.com/problem/subarray-sum-closest/)  

[Subarray Sum II](https://www.lintcode.com/problem/subarray-sum-iii/)  

## Tags
Linked List & Array   
PrefixSum