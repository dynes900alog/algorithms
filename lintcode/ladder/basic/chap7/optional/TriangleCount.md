# 382. Triangle Count

## Description

Given an array of integers, how many three numbers can be found in the array, so that we can build an triangle whose three edges length is the three numbers that we find?

**Example**
```
Given array S = [3,4,6,7], return 3. They are:

[3,4,6]
[3,6,7]
[4,6,7]

Given array S = [4,4,4,4], return 4. They are:

[4(1),4(2),4(3)]
[4(1),4(2),4(4)]
[4(1),4(3),4(4)]
[4(2),4(3),4(4)]
```

## Link
[lintcode](https://www.lintcode.com/problem/triangle-count/)

## Method
* Two Pointers
  * key point : how to convert into a 2sum problem? (a+b == target ---> a+b > target)

## Solution
1.1 Two Pointers
~~~
class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // write your code here
        int ans = 0;
        sort(S.begin(), S.end());
        
        // convert to 2sum: a + b > c 
        for(int i = 2; i < S.size(); i++) {
            int left = 0, right = i - 1;
            while(left < right) {
                if (S[left] + S[right] > S[i]) {
                    ans += right - left;
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        
        return ans;
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
