# 18. Subsets II

## Description
~~~
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
~~~

**Example**
```
Input: [1,2,2]
Output:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

```
**Challenge**  
Can you do it in both recursively and iteratively?

## Link
[lintcode](https://lintcode.com/problem/subsets-ii/)

## Method
1. DFS 
Key point: back tracking template. How to avoid generating duplicated subset?
#1. sort nums   
#2. add condition: "i != startIndex && nums[i] == nums[i-1]"

## Solution
1.1 DFS
~~~
class Solution {
public:
    /**
     * @param nums: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        // write your code here
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());
        vector<int> subset;
        dfsHelper(result, subset, nums, 0);
        
        return result;
    }

    void dfsHelper(vector<vector<int>>& result, vector<int>& subset, vector<int>& nums, int startIndex) {
        result.push_back(subset);
        
        for(int i = startIndex; i < nums.size(); i++) {
            // avoid pick up duplicated element in the same position
            if ( i != startIndex && nums[i] == nums[i -1]) {
                continue;
            }
            
            subset.push_back(nums[i]);
            dfsHelper(result, subset, nums, i + 1);
            subset.pop_back();
        }
    }
};
~~~

## Similar problems
[SubsetII](https://lintcode.com/problem/subsets/)

## Tags
DFS 
