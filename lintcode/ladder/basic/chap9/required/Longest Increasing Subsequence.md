# 76. Longest Increasing Subsequence

## Description
Given a sequence of integers, find the longest increasing subsequence (LIS).

You code should return the length of the LIS.

**Clarification**  
What's the definition of longest increasing subsequence?

* The longest increasing subsequence problem is to find a subsequence of a given sequence in which the subsequence's elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique.

* https://en.wikipedia.org/wiki/Longest_increasing_subsequence

**Example**  
```
For [5, 4, 1, 2, 3], the LIS is [1, 2, 3], return 3
For [4, 2, 4, 5, 3, 7], the LIS is [2, 4, 5, 7], return 4
```

**Challenge**  
Time complexity O(n^2) or O(nlogn)

## Link
[lintcode](https://www.lintcode.com/problem/longest-increasing-subsequence/)

## Method
* DP - Time Complexity is O(n^2)  
  * state: dp[x] - the longest subsequence where the last element is nums[x]
  * function (Top Down): dp[x] = max(dp[y] + 1), y < x and nums[y] < nums[x], for all y:[0, x)
  * initialize: dp[x] = 1
  * answer max(dp[x]), x:[0,size) 

* Greedy
## Solution
1.1 DP - Top Down
~~~
class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> &nums) {
        // write your code here
        int size = nums.size();
        if (size <= 0) {
            return 0;
        }
        
        vector<int> dp(size, 1);
        int maxSubSeq = 0;

        for(int i = 0; i < size; i++) {
            dp[i] = 1;
            for(int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            maxSubSeq = max(maxSubSeq, dp[i]);
        }
        
        return maxSubSeq;
    }
};
~~~

## Similar problems
[Russian Doll Envelopes](https://www.lintcode.com/problem/russian-doll-envelopes/)  
[Frog Jump](https://www.lintcode.com/problem/frog-jump/)  

## Tags
Dynamic Programming 接龙型  
