# 143. Sort Colors II

## Description

Given an array of n objects with k different colors (numbered from 1 to k), sort them so that objects of the same color are adjacent, with the colors in the order 1, 2, ... k.

```
You are not suppose to use the library's sort function for this problem.
k <= n
```
**Example**
```
Given colors=[3, 2, 2, 1, 4], k=4, your code should sort colors in-place to [1, 2, 2, 3, 4].
```
**Challenge**  
A rather straight forward solution is a two-pass algorithm using counting sort. That will cost O(k) extra memory. Can you do it without using extra memory?

## Link
[lintcode](https://www.lintcode.com/problem/sort-colors-ii/)

## Method
* Counting Sort 
* Quick sort partition: nlogk (deduce from k = 1 (O(n)), k = 2 (O(n)), k =3 ... k=n (O(NlogN)))

## Solution
1.1 Three Pointers
~~~
class Solution {
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        int length = colors.size();
        int start = 0, end = length - 1;

        helper(colors, start, end, 1, k);
    }
    
    void helper(vector<int> &colors, int start, int end, int kstart, int kend) {
        if (kstart >= kend || start >= end) {
            return;
        }
        
        // partition into two pars
        int position = partition(colors, start, end, kstart, kend);
        int kmid = kstart + (kend - kstart) / 2;
        helper(colors, start, position -1, kstart, kmid);
        helper(colors, position, end, kmid+1, kend);
    }

    // partition into 2 parts: <= k/2 and > k/2    
    int partition(vector<int> &colors, int start, int end, int kstart, int kend)
    {
        int pivot = kstart + (kend - kstart) / 2;
        while(start <= end) {
            while(start <= end && colors[start] <= pivot) {
                start++;
            }
            
            while(start <= end && colors[end] > pivot) {
                end--;
            }
            
            if (start < end) {
                swap(colors[start], colors[end]);
                start++; end--;
            }
        }
        
        return start;
    }
};
~~~

1.2 O(nk)
```   
(not efficient, will get Time Limit Exceeded error. But you should try to implement the following algorithm for practicing purpose.)
```
~~~
class Solution {
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        int length = colors.size();
        int count = 0;
        int left = 0, right = colors.size() - 1;

        while (count < k) {
            int min = INT_MAX;
            int max = INT_MIN;
            
            // get color range
            for(int i = left; i <= right; i++) {
                min = min(min, colors[i]);
                max = max(max, colors[i]);
            }
            
            // 3-way parition: [min, <max, max]
            int cur = left;
            while (cur <= right) {
                if (colors[cur]== min) {
                    swap(colors[left], colors[cur]);
                    left++; cur++;
                } else if (colors[cur] > min && colors[cur] < max) {
                    cur++;
                } else {
                    swap(colors[cur], colors[right]);
                    right--;
                }
            }
            count += 2;
        }
    }
};
~~~
## Similar problems
[Partition Array II](https://lintcode.com/problem/two-sum/)  
[Sort Colors II](https://lintcode.com/problem/two-sum-input-array-is-sorted/)   
[Wiggle Sort](https://lintcode.com/problem/two-sum-less-than-or-equal-to-target/)  

## Tags
Two Pointers  