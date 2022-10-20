// Name:- Nandini Srivastava.
// Date:- 20 october,2022

/*

Leetcode problem:- 58 (Length of Last Word)
 
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
 
*/

 // Solution

 class Solution {
    public int lengthOfLastWord(String s) {
        int i = s.length() -1;
        int len = 0;
        while (i >=0 && s.charAt(i) == ' ') {
            i --;
        }
        while (i >=0) {
            if (s.charAt(i) == ' ') {
                break;
            }
            i --; len ++;
        }
        return len; // Return the length of last word
        
    }
}
