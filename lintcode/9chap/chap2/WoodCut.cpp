/*
lintcode 183. Wood Cut



Given n pieces of wood with length L[i] (integer array). Cut them into small pieces to guarantee you could have equal or more than k pieces with the same length. What is the longest length you can get from the n pieces of wood? Given L & k, return the maximum length of the small pieces.

 

 

Example
For L=[232, 124, 456], k=7, return 114.

Challenge
O(n log Len), where Len is the longest length of the wood.
*/

class Solution {
public:
    /**
     * @param L: Given n pieces of wood with length L[i]
     * @param k: An integer
     * @return: The maximum length of the small pieces
     */
    int woodCut(vector<int> &L, int k) {
        // write your code here
        // Q: cut into k pieces and the longest length of one piece is max(L)
        // Idea: find the longest length and then by binary search (1,2,3,4,5,...longest) to get the max length to meet >= k
        int start = 1;
        int end = 0; 
        for(int i = 0; i < L.size(); i++) {
            end = L[i] > end ? L[i] : end;
        }
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            int pieces = getPieces(L, mid);
            
            if (getPieces(L, mid) >= k) {
                start = mid;
            }
            else {
                end = mid;
            }
        }
        
        if (getPieces(L, end) >= k) {
            return end;
        }
        
        if (getPieces(L, start) >= k) {
            return start;
        }

        return 0;
        
    }
    
   
    int getPieces(vector<int> &L, int length) {
        int pieces = 0;
        for(int i = 0; i < L.size(); i++) {
            pieces += (L[i] / length);
        }
        return pieces;
    } 
    
};