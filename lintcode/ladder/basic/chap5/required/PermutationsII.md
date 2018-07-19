# 15. Permutations

## Description
~~~
Given a list of numbers, return all possible permutations.
You can assume that there is no duplicate numbers in the list.
~~~

**Example**
```
For nums = [1,2,3], the permutations are:

[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

```
**Challenge**  
Can you do it in both recursively and iteratively?

## Link
[lintcode](https://www.lintcode.com/problem/permutations-ii/)

## Method
1. DFS by recursion  
key point:   
##1 how to determine the neighbors in nums for a existing subset? (use visited[n] to identify neighbors)  
##2 how to avoid pick up repeated elements: sort and nums[i] == nums[i-1]  
##3 identify the case for repeated lements: difference between [1 2(1)]/[1 2(2)] and [1 2(2) 2(1)], (use flag: "visited[i-1] == 0")

2. DFS (swap)

## Solution
1.1 DFS
~~~
class Solution {
public:
    /*
     * @param :  A list of integers
     * @return: A list of unique permutations
     */
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        // write your code here
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());
        
        vector<int> subset;
        vector<bool> visited(nums.size(), false);
        
        dfsHelper(subset, result, nums, visited);
        
        return result;
    }
    
    void dfsHelper(vector<int>& subset, vector<vector<int>>& result, vector<int> &nums, vector<bool>& visited) {
        if (subset.size() == nums.size()) {
            result.push_back(subset);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if (visited[i]) {
                continue;
            }
            
            // avoid repeated case: nums[i] == nums[i-1] && !visited[i-1]       
            if (i != 0 && nums[i] == nums[i-1] && !visited[i-1]) {
                continue;
            }
            
            subset.push_back(nums[i]);
            visited[i] = true;
            dfsHelper(subset, result, nums, visited);
            subset.pop_back();
            visited[i] = false;
        }
    }
};
~~~


1.2 DFS (SWAP version)
~~~
class Solution {
public:
    /*
     * @param :  A list of integers
     * @return: A list of unique permutations
     */
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        // write your code here
        vector<vector<int>> answer;
        
        // not needed if use "canSwap()"
        sort(nums.begin(), nums.end());
        
        permuteUniqueHelper(answer, nums, 0);
        
        return answer;
    }
    
private:
    void permuteUniqueHelper(vector<vector<int>> &answer, vector<int> &nums, int pos) {
        if (pos == nums.size()) {
            answer.push_back(nums);
            return;
        }
        
        for (int i = pos; i < nums.size(); i++) {
            // skip any repeated elements: note the following method is not working!
            if ((i == pos) || (nums[pos] != nums[i] && nums[i] != nums[i-1])) {
            //if (canSwap(nums, pos, i)) {
                // make a move
                swap(nums[pos], nums[i]);
                // DFS
                permuteUniqueHelper(answer, nums, pos+1);
                // move back
                swap(nums[pos], nums[i]);
            }
        }
    }
    
    // if not sorted, cal it (if num[end] already exists in [start end), no need to switch)
    bool canSwap(vector<int> &num, int start, int end) {
        for(int i = start; i < end; i++) {
            if (num[i] == num[end])
                return false;
        }
        
        return true;
    }
};
~~~

## Similar problems
[Permutations](https://www.lintcode.com/problem/permutations/)

## Tags
DFS  
