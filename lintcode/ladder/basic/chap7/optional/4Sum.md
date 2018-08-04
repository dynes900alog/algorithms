# 58. 4Sum

## Description

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?

Find all unique quadruplets in the array which gives the sum of target.
```
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
```

**Example**
```
Given array S = {1 0 -1 0 -2 2}, and target = 0. A solution set is:

(-1, 0, 0, 1)
(-2, -1, 1, 2)
(-2, 0, 0, 2)
```

## Link
[lintcode](https://www.lintcode.com/problem/4sum/)

## Method
* Two Pointers O(n^3)
  * key point : convert into 2Sum issue

## Solution
1.1 Two Pointers
~~~
class Solution {
public:
    /**
     * @param numbers: Give an array
     * @param target: An integer
     * @return: Find all unique quadruplets in the array which gives the sum of zero
     */
    vector<vector<int>> fourSum(vector<int> &numbers, int target) {
        // write your code here
        int length = numbers.size();
        vector<vector<int>> result;
        if (length < 4) {
            return result;
        }
        
        sort(numbers.begin(), numbers.end());
        
        for(int i = 0; i < length - 3; i++) {
            // skip dumplicates
            if (i > 0 && numbers[i] == numbers[i-1]) {
                continue;
            }
            for(int j = i+1; j < length - 2; j++) {
                // skip dumplicates
                if (j > i + 1 && numbers[j] == numbers[j-1]) {
                    continue;
                }
                
                int start = j+1, end = length - 1;
                int res = target - numbers[i] - numbers[j];                
                // 2 sum
                while (start < end) {
                    if (numbers[start] + numbers[end] == res) {
                        vector<int> oneanswer = {numbers[i], numbers[j], numbers[start], numbers[end]};
                        result.push_back(oneanswer);
                        start++; end--;
                        // skip duplicates
                        while(start < end && numbers[start] == numbers[start-1]) {
                            start++;
                        }
                        while(start < end && numbers[end] == numbers[end+1]) {
                        end--;
                        }
                    }
                    else if (numbers[start] + numbers[end] < res) {
                        start++;
                    }
                    else {
                        end--;
                    }
                }
            }
        }
        return result;
    }
};
~~~
## Similar problems
[Two Sum](https://lintcode.com/problem/two-sum/)  
[Two Sum II - Input array is sorted](https://lintcode.com/problem/two-sum-input-array-is-sorted/)   
[Two Sum II - Less than or equal to target](https://lintcode.com/problem/two-sum-less-than-or-equal-to-target/)   
[Two Sum - Unique pairs](https://lintcode.com/problem/two-sum-unique-pairs/)  
[Two Sum - Closest to target](https://lintcode.com/problem/two-sum-closest-to-target/)  
[Two Sum - Difference equals to target](https://lintcode.com/problem/two-sum-difference-equals-to-target/)  
[Two Sum - Greater than target](https://lintcode.com/problem/two-sum-greater-than-target/)  
[Two Sum III- Data structure design](https://lintcode.com/problem/two-sum-data-structure-design/)  
[3Sum](https://lintcode.com/problem/3sum/)

## Tags
Two Pointers  
Hash Table