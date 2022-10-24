// Name: Kavindu Lakmal
// Date: 22/10/2022

/* 
You are given a string s and an integer array indices of the same length. The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.

Return the shuffled string.

Example 1:

Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
Output: "leetcode"
Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.

Example 2:

Input: s = "abc", indices = [0,1,2]
Output: "abc"
Explanation: After shuffling, each character remains in its position.

Implementation:

We use a char array to store the specific element from the string s as specified by the indices array.

For example,

when i = 0, the 4th index element of the char array will contain the 0th element of the string s.
when i = 1. the 5th index element of the char array will contain the 1st element of the string s.
and so on.

Finally, the char array will compose of each character of the string s, and thereby we can return the string using String.valueOf(char[] arr);

*/

class Solution {
    public String restoreString(String s, int[] indices) {
        char[] newString = new char[indices.length];
        for(int i = 0; i < indices.length; i++) {
            newString[indices[i]] = s.charAt(i);
        }
        return String.valueOf(newString);
    }
}