# 622. Frog Jump

## Description
A frog is crossing a river. The river is divided into x units and at each unit there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.  
Given a list of stones' positions (in units) in sorted ascending order, determine if the frog is able to cross the river by landing on the last stone. Initially, the frog is on the first stone and assume the first jump must be 1 unit.  
If the frog's last jump was k units, then its next jump must be either k - 1, k, or k + 1 units. Note that the frog can only jump in the forward direction.

```
* The number of stones is ≥ 2 and is < 1100.
* Each stone's position will be a non-negative integer < 2^31.
* The first stone's position is always 0.
```

**Example**  
```
Given stones = [0,1,3,5,6,8,12,17]

There are a total of 8 stones.
The first stone at the 0th unit, second stone at the 1st unit,
third stone at the 3rd unit, and so on...
The last stone at the 17th unit.

Return true. The frog can jump to the last stone by jumping 
1 unit to the 2nd stone, then 2 units to the 3rd stone, then 
2 units to the 4th stone, then 3 units to the 6th stone, 
4 units to the 7th stone, and 5 units to the 8th stone.

Given stones = `[0,1,2,3,4,8,9,11]`

Return false. There is no way to jump to the last stone as 
the gap between the 5th and 6th stone is too large.
```

## Link
[lintcode](https://www.lintcode.com/problem/frog-jump/)

## Method
* DP - Time Complexity is O(n)  
  * state: dp[x] (unordered_map<int, unordered_set<int>>) - at position x, all the possible steps from any previous stone (代表目前的点能由前面的点跳几步得到，这些步数的集合)
  * function (Bottom Up): dp[x] = (dp[y]), y < x and for all possible steps in dp[y], dp[y]+1/dp[y]/dp[y]-1 can reach to x, y:[0, x)
  * initialize: dp[x] = 1
  * answer dp[size].empty() is false/true 

## Solution
1.1 DP - Bottom Up O(n)
~~~
class Solution {
public:
    /**
     * @param stones: a list of stones' positions in sorted ascending order
     * @return: true if the frog is able to cross the river or false
     */
    bool canCross(vector<int> &stones) {
        // write your code here
        int size = stones.size();
        if (size <= 0 || stones[0] != 0) {
            return false;
        }
        
        // dp[i] : all possible steps set from previous stones
        unordered_map<int, unordered_set<int>>dp;
        for(auto position : stones) {
            dp[position] = unordered_set<int>();    
        }
        
        dp[0].insert(1);
        
        // for each stone : bottom up to update others  dp[stone+k] = k where k is all steps in dp[stone]
        for(auto stone : stones) {
            // for all steps (k, k > 0) in dp[stone], bottom up to update 
            for(auto k : dp[stone]) {
                if (k - 1 > 0 && dp.find(stone + k -1) != dp.end()) {
                    dp[stone+k-1].insert(k-1);
                }
                if (dp.find(stone + k) != dp.end()) {
                    dp[stone+k].insert(k);
                }
                if (dp.find(stone + k + 1) != dp.end()) {
                    dp[stone+k+1].insert(k+1);
                }
            }
        }
        
        return (!dp[stones.back()].empty());
    }
};
~~~


## Similar problems
[Longest Increasing Subsequence](https://www.lintcode.com/problem/longest-increasing-subsequence/))  

## Tags
Dynamic Programming 接龙型  
