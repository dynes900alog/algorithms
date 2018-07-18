# 135. Combination Sum

## Description
~~~
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.
~~~

**Example**
```
Given candidate set [10,1,6,7,2,1,5] and target 8,

A solution set is:

[
  [1,7],
  [1,2,5],
  [2,6],
  [1,1,6]
]
```

## Link
[lintcode](https://lintcode.com/problem/combination-sum-ii/)

## Method
1. DFS 
Key point: DFS templated for subset - 3 key points for a recursion function (function signature, exit condition, body part)    
##1. there are duplicated elements in array, how to avoid picking up them in the same position (generate same subset)?   

## Solution
1.1 DFS
~~~
class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        // write your code here
        vector<vector<int>> result;
        if (num.size() == 0) {
            return result;
        }
        
        vector<int> subset;
        int startIndex = 0;
        
        sort(num.begin(), num.end());
        
        dfsHelper(result, subset, num, target, startIndex);
        
        return result;
    }
    
    void dfsHelper(vector<vector<int>> &result, vector<int> &subset, vector<int> &num, int target, int startIndex) {
        if (target == 0) {
            result.push_back(subset);
            return;
        }
        
        for(int i = startIndex; i < num.size(); i++) {
            if (num[i] > target) {
                break;
            }
            // avoid repeat result: except the first
            if (i > startIndex && num[i] == num[i - 1]) {
                continue;
            }
            
            subset.push_back(num[i]);
            dfsHelper(result, subset, num, target - num[i], i + 1);
            subset.pop_back();
        }
    }
};

~~~

## Similar problems
[Combination Sum](https://lintcode.com/problem/combination-sum)

## Tags
DFS 
