# 74. First Bad Version

## Description

The code base version is an integer start from 1 to n. One day, someone committed a bad version in the code case, so it caused this version and the following versions are all failed in the unit tests. Find the first bad version.

You can call isBadVersion to help you determine which version is the first bad one. The details interface can be found in the code's annotation part.
```
Please read the annotation in code area to get the correct way to call isBadVersion in different language. For example, Java is SVNRepo.isBadVersion(v)
```
## Example
Given n = 5:
```
isBadVersion(3) -> false
isBadVersion(5) -> true
isBadVersion(4) -> true
Here we are 100% sure that the 4th version is the first bad version.
```

## Challenge
You should call isBadVersion as few as possible.

## Link
[lintcode](https://lintcode.com/problem/first-bad-version/)

## Method
* Binary Search  
  * Note: overflow may happens if "start = mid + 1" is used becasue evaluate "start + 1 < end" if mid = 0x7fffffff - 1.  

## Solution
1.1 Bianry Search (Template, without using template, be careful left/right choose based on mide and post processing)

~~~
/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        unsigned int start = 1, end = n;
        
        while (start + 1  < end) {
            unsigned int mid = start + (end - start) / 2;
            if (SVNRepo::isBadVersion(mid)) {
                end = mid;
            }
            else {
                start = mid;  // don't use "mid + 1" to avoid signed integer overflow
            }
        }
        
        if (SVNRepo::isBadVersion(start)) {
            return start;
        }
        
        if (SVNRepo::isBadVersion(end)) {
            return end;
        }
        
        return - 1;
    }
};
~~~

## Similar problems
[Last position of Target](https://www.lintcode.com/problem/last-position-of-target/)  

## Tags
Binary Search