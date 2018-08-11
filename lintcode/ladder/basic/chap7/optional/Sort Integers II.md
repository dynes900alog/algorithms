# 464. Sort Integers II

## Description

Given an integer array, sort it in ascending order. Use quick sort, merge sort, heap sort or any O(nlogn) algorithm.

**Example**
```
Given [3, 2, 1, 4, 5], return [1, 2, 3, 4, 5].
```
## Link
[lintcode](https://www.lintcode.com/problem/sort-integers-ii/)

## Method
* Quick Sort: average time complexity O(nlogn), not stable
  * key point : Partition to avoid overlap and unbalanced partition (caused by equal keys)
* Merge Sort: alwasy O(nlogn) and stable. But need auxillary space O(n)  
  * Bottom Up and Top Down 

## Solution
1.1 Quick Sort
~~~
class Solution {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    void sortIntegers2(vector<int> &A) {
        // write your code here
        if (A.size() <= 0) {
            return;
        }
        
        return quickSort(A, 0, A.size()-1);
    }
    
    void quickSort(vector<int> &A, int start, int end) {
        // 1. exit 
        if (start >= end) {
            return;
        }

        // 2. choose pivot in the middle
        int left = start, right = end;
        int mid = start + (end - start) / 2;
        int pivot = A[mid];
        
        // 3. partition: start <= end, not "<" which can cause overlap
        while(left <= right) {
            //4. Note: "<" pivot", not "<=" pivot or it can cause unbalanced partition
            while(left <= right && A[left] < pivot) {
                left++;
            }
            
            while(left <= right && A[right] > pivot) {
                right--;
            }
            
            if (left <= right) {
                int temp = A[right];
                A[right] = A[left];
                A[left] = temp;
                left++;right--;
                //swap(A[left++], A[right--]);
            }
        }
        
        // "left != right", safe to call recursively. Or it may cause stack overflow
        quickSort(A, start, right);
        quickSort(A, left, end);
    }
};
~~~

1.2 Merge Sort: Top Down
~~~
class Solution {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    void sortIntegers2(vector<int> &A) {
        // write your code here
        if (A.size() <= 0) {
            return;
        }
        
        vector<int> aux(A.size(), 0);
        return mergeSort(A, 0, A.size() -1, aux);
    }

    // Merge Sort: recursion version
    void mergeSort(vector<int> &A, int start, int end, vector<int> &aux) {
        if (start >= end) {
            return;
        }
        
        int mid = start + (end - start) / 2;
        mergeSort(A, start, mid, aux);
        mergeSort(A, mid + 1, end, aux);
        
        // merge two parts
        merge(A, start, mid, end, aux);
    } 
    
    void merge(vector<int> &A, int start, int mid, int end, vector<int> &aux) {
        // merge two parts: 
        // Note: the trick to merge only by one iteration : aux[] first half increase and second half decrease
        for(int i = start; i <= mid; i++) {
            aux[i] = A[i];
        }
        for(int j = mid + 1; j <= end; j++) {
            aux[j] = A[end -j + mid + 1];    
        }

        int i = start, j = end;
        for(int k = start; k <= end ; k++) {
            if (aux[i] <= aux[j]) {
                A[k] = aux[i++];
            }
            else {
                A[k] = aux[j--];
            }
        }
        
        /*  the following is the same but with one more iteration
        int i = start, j = mid + 1, k = 0;
        while (i <= mid && j <= end) {
            if (A[i] <= A[j]) {
                aux[k++] = A[i++];
            }
            else {
                aux[k++] = A[j++];
            }
        }
        
        while (i <= mid) {
            aux[k++] = A[i++];
        }
        
        while (j <= end) {
            aux[k++] = A[j++];
        }
        
        // copy back to A
        k = 0; i = start;
        while (i <= end) {
            A[i++] = aux[k++];
        }
        */
    }
};
~~~

1.3 Merge Sort: Bottom Up
~~~
class Solution {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    void sortIntegers2(vector<int> &A) {
        // write your code here
        if (A.size() <= 0) {
            return;
        }
        
        vector<int> aux(A.size(), 0);
        return mergeSortBottomUp(A, aux);
   }

    // Merge Sort iteravie version: bottom up
    void mergeSortBottomUp(vector<int> &A, vector<int> &aux) {
        int size = A.size();
        for(int sz = 1; sz < size;  sz = sz* 2) {
            for(int i = 0; i < size - sz; i += 2*sz) {
                // merge based on sz, range [i, i+sz, i+2*sz) 
                int start = i;
                int mid = i + sz - 1;
                int end = min(size - 1, i + 2*sz -1);
                merge(A, start, mid, end, aux);
            }
        }
    }
    
    // Merge is the same as TopDown version
};
~~~

## Similar problems
[Sort Integers](https://lintcode.com/problem/sort-integers/)

## Tags
Two Pointers  
