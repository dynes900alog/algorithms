# 31. Partition Array

## Description

Given an array nums of integers and an int k, partition the array (i.e move the elements in "nums") such that:

All elements < k are moved to the left
All elements >= k are moved to the right
Return the partitioning index, i.e the first index i nums[i] >= k.
```
You should do really partition in array nums instead of just counting the numbers of integers smaller than k.
```
**Example**
```
If nums = [3,2,2,1] and k=2, a valid answer is 1.
```
**Challenge**  
Can you partition the array in-place and in O(n)?

## Link
[lintcode](https://www.lintcode.com/problem/partition-array/)

## Method
* Two Pointers: by moving in same direction or in reverse direction (双向双指针/同向双指针)
  * key point : same way as quick sort partition

## Solution
1.1 Two Pointers by moving forward together
~~~
class Solution {
public:
    /**
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int i = 0, j = -1;
        int length = nums.size();
        
        // j: the first position where nums[j] >= k;
        for(i = 0; i < length; i++) {
            // find the postion where it shouldn't  in right part
            if (nums[i] < k) {
                swap(nums[i], nums[++j]);
            }    
        }
        return j;
    }
};
~~~

1.2 Two Pointers: moving reversely
~~~
class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            while (i < j && nums[i] < k) i++;
            while (i < j && nums[j] >= k) j--;
            if (i < j) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                //i++; j--;
            }
        }
        // in the case where i == nums.size() - 1 and nums[i] < k
        if (nums[i] < k) {
            // All [0 ... size) < k
            return i+1;
        }

        return i;
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