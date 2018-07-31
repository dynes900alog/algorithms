# 415. Valid Palindrome

## Description

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
```
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
```
**Example**
```
"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

```

**Challenge**  
O(n) time without extra memory.

## Link
[lintcode](https://lintcode.com/problem/valid-palindrome/)

## Method
* Two Pointers
  * key point : front/back pointers

## Solution
1.1 Two Pointers
~~~
class Solution {
public:
    /**
     * @param s: A string
     * @return: Whether the string is a valid palindrome
     */
    bool isPalindrome(string &s) {
        // write your code here
        // tolower() and isalnum() are c library, transform() and prev() are std c++
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);

        auto it1 = s.begin();
        auto  it2 = std::prev(s.end());
        while (it1 < it2) {
            if (!::isalnum(*it1)) {
                it1++;
            }
            else if (!::isalnum(*it2)) {
                it2--;
            }
            else if (*it1 != *it2) {
                return false;
            }
            else {
                it1++;
                it2--;
            }
        }
        
        return true;
    }
};
~~~


## Similar problems
[Valid Palindrome II](https://lintcode.com/problem/valid-palindrome-ii/)  
## Tags
Two Pointers
