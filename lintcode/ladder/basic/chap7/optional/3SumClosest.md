# 59. 3Sum Closest

## Description

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers.
```
You may assume that each input would have exactly one solution.
```
**Example**
```
For example, given array S = [-1 2 1 -4], and target = 1. The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

```
##Challenge##
O(n^2) time, O(1) extra space

## Link
[lintcode](https://lintcode.com/problem/3sum-closest/)

## Method
* Two Pointers
  
## Solution
1.1 Two Pointers
~~~
class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> &numbers, int target) {
        // write your code here
        int length = numbers.size();
        if (length < 3) {
            return -1;
        }
        
        sort(numbers.begin(), numbers.end());
        
        int minSum = numbers[0] + numbers[1] + numbers[2];
        
        for(int i = 0; i < length -2; i++) {
            if (i > 0 && numbers[i] == numbers[i-1]) {
                continue;
            }
            
            int j = i + 1, k = length - 1;

            while (j < k) {
                int sum = numbers[i] + numbers[j] + numbers[k];
                if (abs(sum - target) < abs(minSum - target)) {
                    minSum = sum;
                }

                if (sum < target) {
                    j++;
                }
                else {
                    k--;
                }
                
            }
        }
        
        return minSum;
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