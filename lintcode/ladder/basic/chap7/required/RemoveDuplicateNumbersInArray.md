# 521. Remove Duplicate Numbers in Array

## Description

Given an array of integers, remove the duplicate numbers in it.

```
You should:

Do it in place in the array.
Move the unique numbers to the front of the array.
Return the total number of the unique numbers.
Notice

You don't need to keep the original order of the integers.
```
**Example**
```
Given nums = [1,3,1,4,4,2], you should:

Move duplicate integers to the tail of nums => nums = [1,3,4,2,?,?]. Return the number of unique integers in nums => 4. Actually we don't care about what you place in ?, we only care about the part which has no duplicate integers.
```

**Challenge**  
Do it in O(n) time complexity.
Do it in O(nlogn) time without extra space.


## Link
[lintcode](http://lintcode.com/en/problem/remove-duplicate-numbers-in-array/)

## Method
* Hash Table and traverse: space O(n) + time O(n)
  
* Sort and remove duplicates by 2 pointers
  * key point : 2 pointers to keep the positions, the condition when copy happens


## Solution
1.1 Sort and Merge
~~~
class Solution {
public:
    /**
     * @param nums an array of integers
     * @return the number of unique integers
     */
    int deduplication(vector<int>& nums) {
        int length = nums.size();

        if (size <= 1>) {
            return size;
        }

        sort(nums.begin(), nums.end());

        /*
        int index = 0;
        for (int i = 0; i < length; i++) {
            if (nums[i] != nums[index]) {
                nums[++index] = nums[i];
            }
        }
        return index+1;
        */
        int left = 0, right = 0;
        while(right < size) {
            if (nums[right] != nums[left]) {
                nums[++left] = nums[right];
            }
            right++;
        }

        return (left + 1);
    }
};       
~~~

1.2 Hash Set
~~~
class Solution {
public:
    /**
     * @param nums an array of integers
     * @return the number of unique integers
     */
    int deduplication(vector<int>& nums) {
        int size = nums.size();

        if (size <= 1>) {
            return size;
        }

        unordered_set<int> hashset;

        int pos = 0;
        for (int i = 0; i < size; i++) {
            if (hashset.find(nums[i]) == hashset.end()) {
                hashset.insert(nums[i]);
                nums[pos++] = nums[i];
            }

        }

        return pos;
    }
};       
~~~

## Similar problems
## Tags
Two Pointers
