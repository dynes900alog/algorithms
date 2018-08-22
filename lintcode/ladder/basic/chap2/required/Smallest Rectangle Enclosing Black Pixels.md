# 600. Smallest Rectangle Enclosing Black Pixels

## Description

An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

**Example**  
For example, given the following image:
```
[
  "0010",
  "0110",
  "0100"
]
```
and x = 0, y = 2,
Return 6.

## Link
[lintcode](https://www.lintcode.com/problem/smallest-rectangle-enclosing-black-pixels/)

## Method
* Binary Search
  * key point : get left/right/up/down of the rectangle by binary search

## Solution
1.1 Binary Search (template)
~~~
class Solution {
public:
    /**
     * @param image: a binary matrix with '0' and '1'
     * @param x: the location of one of the black pixels
     * @param y: the location of one of the black pixels
     * @return: an integer
     */
    int minArea(vector<vector<char>> &image, int x, int y) {
        // write your code here
        // idea: check up/down, left/right area 
        
        int row = image.size();
        if (row <= 0) {
            return -1;
        }
        int col = image[0].size();
        if (col <= 0) {
            return -1;
        }
        
        if (image[x][y] != '1') {
            return -1;
        }
        
        int left, right, up, down;
        int start, end;
        
        // get the most right colum
        start = y;
        end = col - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (checkColum(image, mid)) {
                start = mid;
            }
            else {
                end = mid;
            }
        }
        if (checkColum(image, end)) {
            right = end;
        }
        else {
            right = start;
        }
        
        // get the most left colum
        start = 0;
        end = y;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (checkColum(image, mid)) {
                end = mid;
            }
            else {
                start = mid;
            }
        }
        if (checkColum(image, start)) {
            left = start;
        }
        else {
            left = end;
        }

        
        // get the up most colum
        start = 0;
        end = x;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (checkRow(image, mid)) {
                end = mid;
            }
            else {
                start = mid;
            }
        }
        if (checkRow(image, start)) {
            up = start;
        }
        else {
            up = end;
        }

        // get down row
        start = x;
        end = row - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (checkRow(image, mid)) {
                start = mid;
            }
            else {
                end = mid;
            }
        }
        if (checkRow(image, end)) {
            down = end;
        }
        else {
            down = start;
        }

        return (right - left + 1) * (down - up + 1);
    }

private:    
    bool checkColum(vector<vector<char>> &image, int index) {
        int row = image.size();
        for(int i = 0; i < row; i++) {
            if (image[i][index] == '1') {
                return true;
            }
        }
        
        return false;
    }
    bool checkRow(vector<vector<char>> &image, int index) {
        int colum = image[0].size();
        for(int i = 0; i < colum; i++) {
            if (image[index][i] == '1') {
                return true;
            }
        }
        
        return false;
    }
    
};
~~~

1.2 Binary Search (more compact, but be careful of corner case)
~~~
class Solution {
public:
    /**
     * @param image a binary matrix with '0' and '1'
     * @param x, y the location of one of the black pixels
     * @return an integer
     */
    int minArea(vector<vector<char>>& image, int x, int y) {
        // Write your code here
        int m = image.size();
        if (m == 0)
            return 0;
        int n = image[0].size();
        if (n == 0)
            return 0;

        int start = y;
        int end = n - 1;
        int mid;
        while (start < end) {
            // Note: mid increased by 1 here: if start + 1 = end && start is "1", it can casue endless loop if mid == start!!!
            mid = start + (end - start) / 2 + 1;
            if (checkColumn(image, mid)) {
                start = mid;
            } else {
                end = mid - 1;
            }
        }
        int right = start;
        
        start = 0;
        end = y;
        while (start < end) {
            // No need to increase 1
            mid = start + (end - start) / 2;
            if (checkColumn(image, mid)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        int left = start;
        
        start = x;
        end = m - 1;
        while (start < end) {
            mid = start + (end - start) / 2 + 1;
            if (checkRow(image, mid)) {
                start = mid;
            } else {
                end = mid - 1;
            }
        }
        int down = start;
        
        start = 0;
        end = x;
        while (start < end) {
            mid = start + (end - start) / 2;
            if (checkRow(image, mid)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        int up = start;
        
        return (right - left + 1) * (down - up + 1);
    }
    
    bool checkColumn(vector<vector<char>>& image, int col) {
        for (int i = 0; i < image.size(); i++) {
            if (image[i][col] == '1') {
                return true;
            }
        }
        return false;
    }
    
    bool checkRow(vector<vector<char>>& image, int row) {
        for (int j = 0; j < image[0].size(); j++) {
            if (image[row][j] == '1') {
                return true;
            }
        }
        return false;
    }
};
~~~
## Similar problems
[Find Minimum in Rotated Sorted Array II](https://www.lintcode.com/problem/find-minimum-in-rotated-sorted-array-ii/)  
[Search in Rotated Sorted Array II](https://www.lintcode.com/problem/search-in-rotated-sorted-array-ii/)

## Tags
Binary Search