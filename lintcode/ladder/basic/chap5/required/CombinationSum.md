# 135. Combination Sum

## Description
~~~
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.
~~~

**Example**
```
Given candidate set [2,3,6,7] and target 7, a solution set is:

[7]
[2, 2, 3]

```

## Link
[lintcode](https://lintcode.com/problem/combination-sum/)

## Method
1. DFS 
Key point: DFS templated for subset - 3 key points for a recursion function (function signature, exit condition, body part)  
##1. how to pickup an elment repeatedly?   
##2. exit condition: target == 0 (or sum == target)


## Solution
1.1 DFS
~~~
class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target: An integer
     * @return: A list of lists of integers
     */
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        // write your code here
        vector<vector<int>> result;
        vector<int> subset;
        int startIndex = 0;

        // sort and remove duplicates so we can determine when to terminate 
        removeDuplicates(candidates);

        dfsHelper(result, subset, candidates, target, startIndex);        
        return result;
    }
    
    void dfsHelper(vector<vector<int>>& result, vector<int>& subset, vector<int>& nums, int target, int startIndex) {
        if (target == 0) {
            result.push_back(subset);
            return;
        }

        for(int i = startIndex; i < nums.size(); i++) {
            if (nums[i] > target) {
                break;
            }
            /* Bypass dumplicated elements if only sort candidates
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            */
            subset.push_back(nums[i]);
            dfsHelper(result, subset, nums, target - nums[i], i);
            subset.pop_back();
        }
    }

    void removeDuplicates(vector<int>& candidates) {
        sort(candidates.begin(), candidates.end());
        
        int index = 0;
        for(int i = 0; i < candidates.size(); i++) {
            if (candidates[i] != candidates[index]) {
                candidates[++index] = candidates[i];
            }
        }
        
        for(int i = 0; i < candidates.size() - index -1; i++) {
            candidates.pop_back();
        }
        
    }
};

~~~

## Similar problems
[Combination Sum II](https://lintcode.com/problem/combination-sum-ii)

## Tags
DFS 
