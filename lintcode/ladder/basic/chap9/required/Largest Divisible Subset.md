# 603. Largest Divisible Subset

## Description
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
```
If there are multiple solutions, return any subset is fine.
```
**Example**  
```
Given nums = [1,2,3], return [1,2] or [1,3]

Given nums = [1,2,4,8], return [1,2,4,8]
```

## Link
[lintcode](https://www.lintcode.com/problem/largest-divisible-subsequence/)

## Method
* DP 
  * state: dp[x] - the size of divisible elements where the last element is nums[x]
  * function: dp[x] = max(dp[y] + 1), y < x and nums[x] % nums[y] == 0, for all y:[0, x)
  * initialize: dp[x] = 1, use paths[x] to record the path 
  * answer max(dp[x]), x:[0,size) 

## Solution
1.1 DP 
~~~
class Solution {
public:
    /*
     * @param nums: a set of distinct positive integers
     * @return: the largest subset 
     */
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        // write your code here
        sort(nums.begin(), nums.end());
        
        int size = nums.size();
        
        // state: dp[i] - the number of divisible elements where nums[i] is the last elements
        vector<int> dp(size, 0);
        vector<int> paths(size, 0);
        int maxSubsetSize = 0;
        int lastIndex = -1;
        
        for(int i = 0; i < nums.size(); i++) {
            paths[i] = -1;
            dp[i] = 1;
            
            for(int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    paths[i] = j;
                }    
            }
            
            // update maxSubsetSize and the last element's index
            if (maxSubsetSize <= dp[i]) {
                maxSubsetSize = dp[i];
                lastIndex = i;
            }
        }            
        
        // return result from the lastIndex which has maxSubsetSize
        vector<int> result;
        while(lastIndex != -1) {
            int element = nums[lastIndex];
            result.push_back(element);
            lastIndex = paths[lastIndex];
        }
        
        return result;
    }
};
~~~

## Similar problems
[Longest Increasing Subsequence](https://www.lintcode.com/problem/longest-increasing-subsequence/)  
[Frog Jump](https://www.lintcode.com/problem/frog-jump/)  

## Tags
Dynamic Programming 接龙型  
