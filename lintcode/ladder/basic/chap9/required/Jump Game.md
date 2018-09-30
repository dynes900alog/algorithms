# 116. Jump Game

## Description
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.
···
This problem have two method which is Greedy and Dynamic Programming.

The time complexity of Greedy method is O(n).

The time complexity of Dynamic Programming method is O(n^2).

We manually set the small data set to allow you pass the test in both ways. This is just to let you learn how to use this problem in dynamic programming ways. If you finish it in dynamic programming ways, you can try greedy method to make it accept again.
···

**Example**  
A = [2,3,1,1,4], return true.  
A = [3,2,1,0,4], return false.

## Link
[lintcode](https://www.lintcode.com/problem/jump-game/)

## Method
* DP - Time Complexity is O(n^2)  
  * state: dp[x] if index:x is reachable
  * function (Top Down): dp[x] = true if "dp[y] == true && y + A[y] >= x" for any y:[0, x)
  * initialize: dp[0] = true
  * answer dp[size-1] 

* Greedy
## Solution
1.1 DP - Top Down
~~~
class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &A) {
        // write your code here
        int size = A.size();
        if (size <= 0) {
            return false;
        }
        
        vector<bool> dp(size, false);
        dp[0] = true;
        
        for(int i = 1; i < size; i++) {
            dp[i] = false;
            for(int j = 0; j < i; j++) {
                if (dp[j] && (j + A[j] >= i)) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[size -1];
    }
};
~~~

1.2 DP - Bottom up
~~~
class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &A) {
        // write your code here
        int size = A.size();
        if (size <= 0) {
            return false;
        }
        
        vector<bool> dp(size, false);
        dp[0] = true;
        
        for(int i = 0; i < size; i++) {
            if (dp[i] == false) {
                continue;
            }
            int steps = A[i];
            for(int j = 0; j <= steps; j++) {
                dp[i + j] = true;
            }
        }
        
        return dp[size -1];
    }
};
~~~

1.3 Greedy
~~~
class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &A) {
        // write your code here
        int size = A.size();
        if (size <= 0) {
            return false;
        }

        int farthest = A[0];        

        for(int i = 1; i < size; i++) {
            if (i <= farthest && i + A[i] > farthest) {
                farthest = i + A[i];
            }
        }
        
        return (farthest >= size -1);
    }
};
~~~

## Similar problems
[Jump Game II](https://www.lintcode.com/problem/jump-game-ii/)  
[Rogue Knight Sven](https://www.lintcode.com/problem/rogue-knight-sven/)  

## Tags
Dynamic Programming 坐标型  
Greedy
