# 57. 3Sum

## Description

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
```
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
```
**Example**
For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:
```
(-1, 0, 1)
(-1, -1, 2)
```
## Link
[lintcode](https://www.lintcode.com/problem/3sum/)

## Method
* Two Pointers: time O(n^2) space O(1)
  * key point : convert into 2Sum issue
* Hash Table: time O(n^2) and space O(n)
## Solution
1.1 Two pointers
~~~
class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int>> threeSum(vector<int> &numbers) {
        // write your code here
        vector<vector<int>> result;
        if (numbers.size() <= 2) {
            return result;
        }
        
        sort(numbers.begin(), numbers.end(), std::less<int>());
        
        for(int i = 0; i < numbers.size() - 2; i++) {
            if (i > 0 && numbers[i] == numbers[i -1]) {
                continue;
            }

            // b + c = - a;
            int target = -numbers[i];
            
            // 2 sum
            int j = i + 1, k = numbers.size() - 1;
            while (j < k) {
                if (numbers[j] + numbers[k] == target) {
                    vector<int> oneanswer = {numbers[i], numbers[j], numbers[k]};
                    result.push_back(oneanswer);
                    j++; k--;
                    // skip duplicates
                    while(j < k && numbers[j] == numbers[j-1]) {
                        j++;
                    }
                    while(j < k && numbers[k] == numbers[k+1]) {
                        k--;
                    }
                }
                else if (numbers[j] + numbers[k] < target) {
                    j++;
                }
                else {
                    k--;
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