# Little Endian or Big Endian

## Description

Write a program to determine if the machine is little or big endian

**Example**

## Link

## Method
* Save a multibyte data-types (integers, float etc) in memory, but retrieve only one byte from memory.
  *  little endian system saves the multbyte data-type's last byte first, while big endian saves the first byte first.

## Solution
1.1 
~~~
class Solution {
public:
    /*
     * @param x: An integer
     * @return: An integer
     */
    bool isLittleEndian() {
        // write your code here
        unsigned int temp = 0x00000001;
        char* tempAddr = (char *) &temp;
        if (*tempAddr) {
            return true;  // little endian
        }
        else {
            return false;
        }

    }
};
~~~
## Similar problems

## Tags
Bit Manipulate