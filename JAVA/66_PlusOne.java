// Name: Ayush Sharma
// Date: 24/10/2022

/*
Problem Statement :
66. Plus One (LEETCODE - Easy)
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the
integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer
does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.

Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

Example 3:
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].

Solution Explanation :-
In the given question, the array represents a number. The elements in array represent the digits of number. We need to
add 1 to that number. We do so by adding 1 to the last element and checking if the last element is greater than 10 or
not. If it is greater than 10, we will keep the modulus 10 and carry forward to the next element and add it. We keep on
doing so by traversing the whole array from backwards to forward.

Time Complexity - O(N)
Extra Space Complexity - O(1)
*/

class Solution {
    public int[] plusOne(int[] digits) {
        if (digits[digits.length - 1] < 9) {
            digits[digits.length - 1]++;
            return digits;
        } else {
            digits[digits.length - 1]++;
            for (int i = digits.length - 1; i > 0; i--) {
                if (digits[i] >= 10) {
                    digits[i - 1] += digits[i] / 10;
                    digits[i] = digits[i] % 10;
                }
            }
            if (digits[0] < 10) {
                return digits;
            } else {
                int[] arr = new int[digits.length + 1];
                arr[0] = digits[0] / 10;
                arr[1] = digits[0] % 10;
                System.arraycopy(digits, 1, arr, 2, arr.length - 2);
                return arr;
            }
        }
    }
}