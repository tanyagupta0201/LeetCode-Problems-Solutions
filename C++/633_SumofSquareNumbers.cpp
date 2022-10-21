//Name :- Pushkar Roy
//Date :- 05-10-2022
/*
Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:
Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:
Input: c = 3
Output: false
 */

class Solution {
  public:
    //make function for check square or not
    bool judgeSquareSum(int c) {
      long long int l = 0;

      long long int r = sqrt(c);
      // check condition for loop
      while (l <= r) {
      // find range for checking
      long long int value = (l * l) + (r * r);
      // if value matchecd with given number return true
      if (value == c) {
          return true;
        }
      // if value greater than given number
      else if (value > c) {
          r--;
        }
      // if value less than given number
        else if (value < c) {
          l++;
        }
      }
     // if value not matched
      return false;
    }
};
//TC :- O(logn) because we use Binary search technique
//SC :- O(1)  store nothing
