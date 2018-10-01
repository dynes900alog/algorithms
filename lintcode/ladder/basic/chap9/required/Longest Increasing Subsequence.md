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

* Optimized by Binary Search O(nlogn)
  * 思路是先建立一个空的dp数组，然后开始遍历原数组，对于每一个遍历到的数字，我们用二分查找法在dp数组找第一个不小于它的数字，如果这个数字不存在，那么直接在dp数组后面加上遍历到的数字，如果存在，则将这个数字更新为当前遍历到的数字，最后返回dp数字的长度即可，特别注意的是dp数组的值可能不是一个真实的LIS. 比如若输入数组nums为{4, 2， 4， 5， 3， 7}，那么算完后的dp数组为{2， 3， 5， 7}，可以发现它不是一个原数组的LIS，只是长度相等而已，千万要注意这点。
* Use STL lower_bound to replace binary search
## Solution
1.1 DP - Top Down O(n^2)
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

1.2 DP - optimized to O(nlogn) by binary search
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
        
        vector<int> dp(size, INT_MAX);

        for(int i = 0; i < size; i++) {
            int index = binarySearch(dp, nums[i]);
            dp[index] = nums[i];
        }
        
        // return the max position where dp[i] != INT_MAX
        for(int i = size - 1; i >= 0; i--) {
            if (dp[i] != INT_MAX) {
                return i + 1;
            }
        }
        
        return 0;
    }
    
    
    // find the first position in nums[pos] where nums[pos] >= target
    int binarySearch(vector<int> &nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid;
            }
            else {
                end = mid;
            }
        }
        
        if (nums[start] >= target) {
            return start;
        }
        
        return end;
    }
};
~~~

1.3 STL lower_bound   
Note: similar to binary search, STL lower_bound返回数组中第一个不小于指定值的元素
~~~
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for (auto a : nums) {
            auto it = lower_bound(v.begin(), v.end(), a);
            if (it == v.end()) v.push_back(a);
            else *it = a;
        }
　　　　　 　return v.size();
    }
};
~~~


## Similar problems
[Russian Doll Envelopes](https://www.lintcode.com/problem/russian-doll-envelopes/)  
[Frog Jump](https://www.lintcode.com/problem/frog-jump/)  

## Tags
Dynamic Programming 接龙型  
