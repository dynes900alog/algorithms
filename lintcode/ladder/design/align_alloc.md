# Aligned Malloc in C

## Description
~~~
Write an aligned malloc & free function that takes number of bytes and aligned byte (which is always power of 2).
~~~

**Example**
```
align_malloc (1000,128) will return a memory address that is a multiple of 128 and that points to memory of size 1000 bytes.
aligned_free() will free memory allocated by align_malloc. 
```
**Challenge**  
N/A

## Link
[embedded](https://tianrunhe.wordpress.com/tag/low-level/)

## Method
We will use malloc routine provided by C to implement the functionality.
Allocate memory of size (bytes required + alignment – 1 + sizeof(void*)) using malloc.  

alignment: malloc can give us any address and we need to find a multiple of alignment. (Therefore, at maximum multiple of alignment, we will be alignment-1 bytes away from any location.)  

sizeof(size_t): We are returning a modified memory pointer to user, which is different from the one that would be returned by malloc. We also need to extra space to store the address given by malloc, so that we can free memory in aligned_free by calling free routine provided by C.  

If it returns NULL, then aligned_malloc will fail and we return NULL.
Else, find the aligned memory address which is a multiple of alignment (call this p2).  

Store the address returned by malloc (e.g., p1 is just size_t bytes ahead of p2), which will be required by aligned_free.
Return p2.

## Solution
1.1 
~~~
class Solution {
public:
    /**
     * @param nums: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    void* aligned_malloc(size_t required_bytes, size_t alignment) {
        //We want it to be a power of two since align_up operates on powers of two
        assert((alignment & (alignment - 1)) == 0);
    
        void* p1;   // original block
        void** p2;  // aligned block
        size_t offset = alignment - 1 + sizeof(void *);
        if ((p1 = (void *)malloc(required_bytes + offset)) == NULL) {
            return NULL;
        }

        p2 = (void** )(( (size_t) (p1) + offset) & ~(alignment - 1));
        p2[-1] = p1;
        return (void *)p2;
    }

    void free(void* p) {
        free(((void**)p)[-1])
    }

};
~~~

## Similar problems
[Embedded](https://tianrunhe.wordpress.com/tag/low-level/)

## Tags
Embedded 
