# 41. Maximum Subarray

## Description
~~~
Given an array of integers, find a contiguous subarray which has the largest sum.
~~~

**Example**
```
Given the array [−2,2,−3,4,−1,2,1,−5,3], the contiguous subarray [4,−1,2,1] has the largest sum = 6.
```

## Challenge
Can you do it in time complexity O(n)?

## Link
[lintcode](https://www.lintcode.com/problem/maximum-subarray/)

## Method
* PrefixSum  
    * Key point: if sum[0, i] == sum[0,j], we have "sum[i+1,j] == 0";use hash table to save all sum/index 
* Dynamic Programming

## Solution
1.1  PrefixSum
~~~
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> &nums) {
        // write your code here
        if (nums.size() == 0) {
            return 0;
        }
        
        int sum = 0; // sum: 0:i
        int maxSubSum = INT_MIN; // subarray sum
        int minSum = 0; // minimum sum of sum: 0 : i -1
        
        for(int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
            int curMaxSubSum = sum - minSum;
            maxSubSum = max(maxSubSum, curMaxSubSum);
            minSum = min(sum, minSum);
        }
        
        return maxSubSum;
    }
};
~~~

1.2 Dynamic Programming
~~~
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> &nums) {
        // write your code here
        if (nums.size() == 0) {
            return 0;
        }

        int maxSum = INT_MIN;
        vector<int> dp(nums.size()+1, 0);
        dp[0] = 0;
        
        for(int i = 1; i <= nums.size(); i++) {
            dp[i] = dp[i-1] > 0 ? dp[i-1] + nums[i-1] : nums[i-1];
            maxSum = max(maxSum, dp[i]);
        }
        
        return maxSum;
    }
};
~~~

## Similar problems
[Maximum Subarray IV](https://www.lintcode.com/problem/maximum-subarray-iv/)  
[Maximum Subarray V](https://www.lintcode.com/problem/maximum-subarray-v/)
[Minimum Subarray IV](https://www.lintcode.com/problem/minimum-subarray/)  

## Tags
Array
PrefixSum
Dynamic Programming
