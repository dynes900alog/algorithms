# 602. Russian Doll Envelopes

## Description
You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

**Example**  
```
Given envelopes = [[5,4],[6,4],[6,7],[2,3]],
the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
```

## Link
[lintcode](https://www.lintcode.com/problem/russian-doll-envelopes/)

## Method
* DP - Sort and use the same way as "Longest Increasing Subsequence"
  * Note: Time Complexity O(n^2)
  * dp[i] : the longest increasing subsequence where nums[i] is the last element in the subsequence
  
* Binary Search
  * 给信封排序，但是这次排序和上面有些不同，信封的宽度还是从小到大排，但是宽度相等时，我们让高度大的在前面。那么现在问题就简化了成了找高度数字中的LIS，完全就和之前那道Longest Increasing Subsequence一样了.
  
## Solution
1.1 DP without optimization 
~~~
bool Compare(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) {
        return a.second < b.second;
    } 
    else {
        return a.first < b.first;
    }    
}

class Solution {
public:
    /*
     * @param envelopes: a number of envelopes with widths and heights
     * @return: the maximum number of envelopes
     */
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        // write your code here
        // idea: sort envelopes by w, and question is converted to longest increasing subsequence by h 
        int size = envelopes.size();
        if (size <= 0) {
            return 0;
        }
        
        // sort ascending
        sort(envelopes.begin(), envelopes.end(), Compare);
        
        vector<int> dp(size, 0);
        dp[0] = 1;
        int maxSubSeq = 0;
        
        for(int i = 1; i < size; i++) {
            dp[i] = 1;
            for(int j = 0; j < i; j++) {
                if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
                    dp[i] = max(dp[i], dp[j] + 1); 
                }
            }
            maxSubSeq = max(maxSubSeq, dp[i]);
        }
        
        return maxSubSeq;
    }
};
~~~

1.2 DP + Binary Search 
~~~
Note: Compare function here - if width is equal, height is descendant
bool Compare(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) {
        return a.second > b.second;
    } 
    else {
        return a.first < b.first;
    }    
}

class Solution {
public:
    /*
     * @param envelopes: a number of envelopes with widths and heights
     * @return: the maximum number of envelopes
     */
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        // write your code here
        // idea: sort envelopes by w, and question is converted to longest increasing subsequence by h 
        int size = envelopes.size();
        if (size <= 0) {
            return 0;
        }
        
        // sort ascending
        sort(envelopes.begin(), envelopes.end(), Compare);
        
        vector<int> dp;
        dp.push_back(envelopes[0].second);
        
        for(int i = 1; i < size; i++) {
            int index = binarySearch(dp, envelopes[i].second);
            if (index == -1) {
                dp.push_back(envelopes[i].second);
            }
            else {
                dp[index] = envelopes[i].second;
            }
        }
        
        return dp.size();
    }
    
    // find the first postion where nums[position] >= target
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
        
        if (nums[end] >= target) {
            return end;
        }
        
        return -1;
    }
};
~~~
## Similar problems
[Longest Increasing Subsequence](https://www.lintcode.com/problem/longest-increasing-subsequence/)  
[Frog Jump](https://www.lintcode.com/problem/frog-jump/)  

## Tags
Dynamic Programming 接龙型  
