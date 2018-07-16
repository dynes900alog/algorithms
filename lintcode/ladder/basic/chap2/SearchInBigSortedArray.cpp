/*
lintcode 447 Search in a Big Sorted Array
 

Given a big sorted array with positive integers sorted by ascending order. The array is so big so that you can not get the length of the whole array directly, 
and you can only access the kth number by ArrayReader.get(k) (or ArrayReader->get(k) for C++). Find the first index of a target number. Your algorithm should be in O(log k), 
where k is the first index of the target number.

Return -1, if the number doesn't exist in the array.

 

 

Example

Given [1, 3, 6, 9, 21, ...], and target = 3, return 1.

Given [1, 3, 6, 9, 21, ...], and target = 4, return -1.    
*/

    int searchBigSortedArray(ArrayReader *reader, int target) {
        // 1. use binary search to roughly get the index where ArrayReader->get(index) >= target ("O(logk)")
        // 2. continue using binary search to get target in [0, index]
        int index = 1;
        while (ArrayReader->get(index-1) < target ) {
            index = 2*index;
        }
        
        int start = 0, end = index;
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            int current = ArrayReader->get(mid);
            if (current == target) {
                end = mid;
            }
            else if (current < target) {
                start = mid;
            }
            else {
                end = mid;
            }
        }
        
        if (ArrayReader->get(start) == target) {
            return start;
        }
        
        if (ArrayReader->get(end) == target) {
            return end;
        }
        
        return -1;
    }