# 547. Intersetction of Two Arrays

## Description

Given two arrays, write a function to compute their intersection. 
```
Each element in the result must be unique.
The result can be in any order.
```

**Example**
```
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
```

**Challenge**  
Can you implement it in three different algorithms?

## Link
[lintcode](https://www.lintcode.com/problem/intersection-of-two-arrays/)

## Method
* Sort and Merge
  * key point : simulate merge sort process

* Hash Set 

* Binary Search

## Solution
1.1 Sort and Merge
~~~
class Solution {
public:
    
    /*
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> nums1, vector<int> nums2) {
        // write your code here
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        int i = 0, j = 0;
        
        vector<int> result;
        
        while(i < len1 && j < len2) {
            if (nums1[i] < nums2[j]) {
                i++;
            }
            else if (nums1[i] > nums2[j]) {
                j++;
            }
            else {
                // don't save duplicated elements
                if (result.empty() || result.back() != nums1[i]) {
                    result.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }
    
        return result;
    }
};    
~~~


1.2 Hash Set
~~~
class Solution {
public:
    
    /*
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> nums1, vector<int> nums2) {
        // write your code here
        // Hash Set 
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        vector<int> result;
        
        if (len1 <= 0 || len2 <= 0) {
            return result;
        }
        
        unordered_set<int> hashset;
        
        for(int i = 0; i < len1; i++) {
            hashset.insert(nums1[i]);
        }
        
        unordered_set<int> resultSet;
        for(int i = 0; i < len2; i++) {
            if (hashset.find(nums2[i]) != hashset.end()) {
                resultSet.insert(nums2[i]);
            }
        }
        
        // copy from resultSet to result
        unordered_set<int>::iterator it;
        for(it = resultSet.begin(); it != resultSet.end(); it++) {
            result.push_back(*it);
        }
        
        return result;
    }
};
~~~

1.3 Binary Search
~~~
class Solution {
public:
    
    /*
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> nums1, vector<int> nums2) {
        // write your code here
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        vector<int> result;
        
        if (len1 <= 0 || len2 <= 0) {
            return result;
        }
        
        // sort the one with smaller length 
        vector<int>& src = nums1;
        vector<int>& dst = nums2;
        sort(src.begin(), src.end());

        /*
        if (len1 < len2) {
            src = nums1; dst = nums2;
            sort(nums1.begin(), nums1.end());
        }
        else {
            src = nums2; dst = nums1;
            sort(nums2.begin(), nums2.end());
        }
        */
        
        unordered_set<int> resultSet;
        for(int i = 0; i < dst.size(); i++) {
            if (resultSet.find(dst[i]) != resultSet.end()) {
                continue;
            }
            
            if (BinarySearch(src, dst[i])) {
                resultSet.insert(dst[i]);
            }
        }
        
        // copy from resultSet to result
        for(auto num : resultSet) {
            result.push_back(num);
        }
        
        /*
        unordered_set<int>::iterator it;
        for(it = resultSet.begin(); it != resultSet.end(); it++) {
            result.push_back(*it);
        }
        */
        
        return result;        
        
    }
    
    bool BinarySearch(vector<int> &src, int target) {
        int start = 0;
        int end = src.size() - 1;
        
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (src[mid] > target) {
                end = mid;    
            }
            else if (src[mid] < target) {
                start = mid;
            }
            else {
                return true;
            }
        }
        
        if (src[start] == target) {
            return true;
        }
        
        if (src[end] == target) {
            return true;
        }
        
        return false;
    }

};
~~~

## Similar problems
[Intersection of Two Arrays II](https://www.lintcode.com/problem/intersection-of-two-arrays-ii/)  
## Tags
Array
