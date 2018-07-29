# 41. Maximum Subarray

## Description
~~~
Given an array of integers, find a contiguous subarray which has the largest sum.

The subarray should contain at least one number.

~~~

**Example**
```
Given the array [−2,2,−3,4,−1,2,1,−5,3], the contiguous subarray [4,−1,2,1] has the largest sum = 6.
```
**Challenge**

Can you do it in time complexity O(n)?

## Link
[lintcode](https://www.lintcode.com/problem/maximum-subarray)

## Method
* PrefixSum  
    * Key point: 令 PrefixSum[i] = A[0] + A[1] + … A[i - 1], PrefixSum[0] = 0  
易知构造 PrefixSum 耗费 O(n) 时间和 O(n) 空间
如需计算子数组从下标i到下标j之间的所有数之和
则有 Sum(i~j) = PrefixSum[j + 1] - PrefixSum[i]
* Dynamic Programming 
    * Key point: dp[i] is defined as - the maximum sum of continous subarray that the last element has array of index "i"
## Solution
1.1 
~~~
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> &nums) {
        // write your code here
        // prefix sum 
        int size = nums.size();
        if (size <= 0) {
            return 0;
        }
        
        int sum = 0;
        int minsum = 0;
        int maxsum = INT_MIN;
        
        for(int i = 0; i < size; i++) {
            sum += nums[i];
            maxsum = max(maxsum, sum -minsum);
            minsum = min(minsum, sum);
        }
        
        return maxsum;
    }
};
~~~

1.2 DP
~~~
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> &nums) {
        // write your code here
        return dpSolution(nums);
    }
    
    int dpSolution(vector<int> & nums) {
        // DP 
        int size = nums.size();
        if (size <= 0) {
            return 0;
        }
        
        vector<int> dp(size, 0);
        dp[0] = nums[0];
        int maxsum = dp[0];
        
        for(int i = 1; i < size; i++) {
            dp[i] = (dp[i-1] > 0) ? dp[i-1] + nums[i] : nums[i];
            maxsum = (dp[i] > maxsum) ? dp[i] : maxsum;
        }
        
        return maxsum;
    }
};
~~~

## Similar problems
[Maximum Subarray II](https://www.lintcode.com/problem/maximum-subarray-ii/)  

[Maximum Subarray III](https://www.lintcode.com/problem/maximum-subarray-iii/)  

## Tags
Linked List & Array 
