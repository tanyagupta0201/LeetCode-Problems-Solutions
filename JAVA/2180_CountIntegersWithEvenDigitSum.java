// Name:- Vishal Singh
// Date:- 05 October 2022
/*
 Problem Statement: 2180. Count Integers With Even Digit Sum
Given a positive integer num, return the number of positive integers less than or equal to num whose digit sums are even.

The digit sum of a positive integer is the sum of all its digits.

Example 1:

Input: num = 4
Output: 2
Explanation:
The only integers less than or equal to 4 whose digit sums are even are 2 and 4.    

Example 2:

Input: num = 30
Output: 14
Explanation:
The 14 integers less than or equal to 30 whose digit sums are even are
2, 4, 6, 8, 11, 13, 15, 17, 19, 20, 22, 24, 26, and 28.

Constraints:

1 <= num <= 1000

 */

 //Solution
class Solution {
    //Creating a function for finding the digits sum
    int getSum(int n) {
        //initializing the sum variable
      int sum = 0;
        //looping through the digits
      while (n != 0) {
        sum = sum + n % 10;
        n = n / 10;
      }
      //returning the sum
      return sum;
    }
    //Creating a function for finding the even digit sum
    public int countEven(int num) {
    //Creating a variable for storing the count
      int k = -1;
      for (int i = 0; i <= num; i++) {
        if (getSum(i) % 2 == 0) {
          k++;
        }
      }
      //Returning the even digit sum
      return k;
    }
  }