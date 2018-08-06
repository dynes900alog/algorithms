# 5. Kth Largest Element

## Description

Find K-th largest element in an array.
```
You can swap elements in the array
```

**Example**
```
In array [9,3,2,4,8], the 3rd largest element is 4.

In array [1,2,3,4,5], the 1st largest element is 5, 2nd largest element is 4, 3rd largest element is 3 and etc.
```

## Link
[lintcode](https://www.lintcode.com/problem/kth-largest-element/)

## Method
* Two Pointers O(nlongn)
  * key point : use both recursive and non-recursive ways. Non-recursive - condition to exit
## Solution
1.1 Two Pointers
~~~
class Solution {
public:
    /*
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> &nums) {
        // write your code here
        if (nums.size() <= 0) {
            return 0;
        }
        if (n <= 0) {
            return 0;
        }
        
        // partion
        int start = 0, end = nums.size() - 1;
        
        // convert to the kth smallest number
        return helper(nums, start, end, end - n + 2);
        
    }
    
    int helper(vector<int>  &nums, int start, int end, int k) {
        if (start == end) {
            return nums[start];
        }
        
        int position = partition(nums, start, end);
        if (position + 1 == k) {
            return nums[position];
        }
        else if (position + 1 < k) {
            return helper(nums, position + 1, end, k);
        }
        else {
            return helper(nums, start, position - 1, k);
        }
    }
    
    // return index of pivot position: note how to parition
    int partition(vector<int> &nums, int start, int end) {
        int pivot = nums[start];
        int i = start, j = end;
        // partion into 3 parts, [ < pivot, = pivot, >=pivot]
        while(i < j) {
            while(i < j && nums[j] >= pivot) {
                j--;
            }
            nums[i] = nums[j];
            
            while(i < j && nums[i] < pivot) {
                i++;
            }
            nums[j] = nums[i];
        }
        
        nums[i] = pivot;
        
        return i;
    }
};
~~~

1.2 
~~~
class Solution {
public:
    /*
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> &nums) {
        // write your code here
        if (nums.size() <= 0) {
            return 0;
        }
        if (n <= 0) {
            return 0;
        }
        
        // partion
        int start = 0, end = nums.size() - 1;
        
        // partition by decreasing [ > pivot, = pivot, <= pivot]
        // index will be the partition pivot postion
        while (start < end) {
            int pivot = nums[end];
            int index = start -1;
            // 2 pointers: i/index
            for(int i = start; i < end; i++) {
                if (nums[i] > pivot) {
                    swap(nums[i], nums[++index]);
                }
            }
            
            swap(nums[++index], nums[end]);
            
            if (index + 1 == n) {
                return nums[index];
            }
            else if (index + 1 < n) {
                start = index + 1;
            }
            else {
                end = index - 1;
            }
        }
        
        if (start + 1 == n) {
            return nums[start];
        }
        
        return -1;
    }
};
~~~
## Similar problems
[Kth Largest Element II](https://lintcode.com/problem/kth-largest-element-ii/)  
[Kth Smallest Numbers in Unsorted Array](https://www.lintcode.com/problem/kth-smallest-numbers-in-unsorted-array/)

## Tags
Two Pointers  