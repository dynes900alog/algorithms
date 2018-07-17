# 17. Subsets

## Description
~~~
Given a set of distinct integers, return all possible subsets.
~~~

**Example**
```
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

```
**Challenge**  
Can you do it in both recursively and iteratively?

## Link
[lintcode](https://lintcode.com/problem/subsets/)

## Method
1. DFS 
Key point: back tracking template 

2. Bitmap 
key point: use "n bits" to represent all combinations([0, 2^n]). "1" means the index of nums should be selected, "0" not selected

3. BFS

## Solution
1.1 DFS
~~~
class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        // write your code here
        vector<vector<int>> result;
        vector<int> subset;
        
        sort(nums.begin(), nums.end());
        subsetsHelper(result, subset, nums, 0);
        
        return result;
    }

private:
    // Recursion
    void subsetsHelper(vector<vector<int>> &result, vector<int> &subset, vector<int> &nums, int pos) {
        result.push_back(subset);
        
        for(int i = pos; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            subsetsHelper(solution, subset, nums, i+1);
            subset.pop_back();
        }
    }
    
};

/* 
Another way of DFS:
使用组合类搜索的专用深度优先搜索算法。
一层一层的决策每个数要不要放到最后的集合里。
*/
public class Solution {
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> results = new ArrayList<>();
        Arrays.sort(nums);
        dfs(nums, 0, new ArrayList<Integer>(), results);
        return results;
    }
    
    // 1. 递归的定义
    // 以 subset 开头的，配上 nums 以 index 开始的数所有组合放到 results 里
    private void dfs(int[] nums,
                     int index,
                     List<Integer> subset,
                     List<List<Integer>> results) {
        // 3. 递归的出口
        if (index == nums.length) {
            results.add(new ArrayList<Integer>(subset));
            return;
        }
        
        // 2. 递归的拆解
        // (如何进入下一层)
        
        // 选了 nums[index]
        subset.add(nums[index]);
        dfs(nums, index + 1, subset, results);
        
        // 不选 nums[index]
        subset.remove(subset.size() - 1);
        dfs(nums, index + 1, subset, results);
    }
}
~~~

1.2 Bitwise
~~~
class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        // write your code here
        vector<vector<int>> result;
        
        sort(nums.begin(), nums.end());
        subsetHelperBit(result, nums);
        
        return result;
    }

private:
    // Use bitmap to resolve
    /* 使用二进制法枚举子集: n个数有2^n个子集，每个子集对应一个二进数,每位二进制对应一个数。二进制的位权为0表示子集不包含那个数，二进制的位权为1表示子集包含那个数。
    */
    void subsetHelperBit(vector<vector<int>> &solution, vector<int> &nums) {
        int size = nums.size();
        // [0, 2^size) for corresponding interger, check each bit set/clear
        int numbers = 1 << size;
        for(int i = 0; i < numbers; i++) {
            // for each number, check 1-bit postions and take them as one subset
            vector<int> subset;
            for(int j = 0; j < size; j++) {
                if (i & (1 << j)) {
                    subset.push_back(nums[j]);
                }
            }
            solution.push_back(subset);
        }
    }
};
~~~

1.3 BFS
~~~
class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        // write your code here
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        vector<int> subset0;
        queue<int> q;
        q.push(subset0);

        while(!q.empty()) {
            vector<int> subset = q.front();
            q.pop();
            result.push_back(subset);

            for(int i = 0; i < nums.size(); i++) {
                if (subset.size() == 0 || subset[subset.size() -1] < nums[i]) {
                    vector<int> nextSubset(subset);
                    nextSubset.add(nums[i]);
                    q.push(nextSubset);
                }
            }
        }

        return result;
    }
};

~~~

## Similar problems
[SubsetII](https://lintcode.com/problem/subsets-ii/)

## Tags
DFS  
Bitwise
