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
[lintcode](https://www.lintcode.com/problem/permutations/)

## Method
1. DFS by recursion
Key point: back tracking template 

2. DFS without recursion

3. BFS
key point: how to determine the neighbors in nums for a existing subset?   

## Solution
1.1 DFS
~~~
class Solution {
public:
    /*
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int>> permute(vector<int> &nums) {
        // write your code here
        vector<vector<int>> answer;
        if (nums.size() == 0) {
            answer.push_back(vector<int>());
            return answer;
        }
        
        
        vector<int> oneanswer;

        permuteHelper(answer, oneanswer, nums);
        
        return answer;
    }

private:
    void permuteHelper(vector<vector<int>> &answer, vector<int> &oneanswer, vector<int> &nums) {
        if (oneanswer.size() == nums.size()) {
            answer.push_back(oneanswer);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            // Or use visited[i] = true/false to record history
            if (find(oneanswer.begin(), oneanswer.end(), nums[i]) == oneanswer.end()) {
                oneanswer.push_back(nums[i]);
                permuteHelper(answer, oneanswer, nums);
                oneanswer.pop_back();
            }
        }
    }
    
    // Another solution
    void permuteHelper02(vector<vector<int>> &answer, vector<int> &nums, int pos) {
        
        // Is it a solution?
        if (pos == nums.size()) {
            answer.push_back(nums);
            return;
        }
        
        // Continue searching all other solutions
        for(int i = pos; i < nums.size(); i++) {
            swap(nums[i], nums[pos]);
            permuteHelper02(answer, nums, pos+1);
            swap(nums[i], nums[pos]);
        }
    }    
    
};
~~~


1.2 DFS (no recursion, not verfied)
~~~
// Non-Recursion
class Solution {
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    public List<List<Integer>> permute(int[] nums) {
        ArrayList<List<Integer>> permutations
             = new ArrayList<List<Integer>>();
        if (nums == null) {
            
            return permutations;
        }

        if (nums.length == 0) {
            permutations.add(new ArrayList<Integer>());
            return permutations;
        }
        
        int n = nums.length;
        ArrayList<Integer> stack = new ArrayList<Integer>();
        
        stack.add(-1);
        while (stack.size() != 0) {
            Integer last = stack.get(stack.size() - 1);
            stack.remove(stack.size() - 1);
            
            // increase the last number
            int next = -1;
            for (int i = last + 1; i < n; i++) {
                if (!stack.contains(i)) {
                    next = i;
                    break;
                }
            }
            if (next == -1) {
                continue;
            }
            
            // generate the next permutation
            stack.add(next);
            for (int i = 0; i < n; i++) {
                if (!stack.contains(i)) {
                    stack.add(i);
                }
            }
            
            // copy to permutations set
            ArrayList<Integer> permutation = new ArrayList<Integer>();
            for (int i = 0; i < n; i++) {
                permutation.add(nums[stack.get(i)]);
            }
            permutations.add(permutation);
        }
        
        return permutations;
    }
}

~~~

## Similar problems
[Permutations II](https://www.lintcode.com/problem/permutations-ii/)

## Tags
DFS  
