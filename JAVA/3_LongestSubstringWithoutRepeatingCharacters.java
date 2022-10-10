// Name: Souvik Pal
// Date: 04/10/2022

/*
Problem Statement :
3. Longest Substring Without Repeating Characters (LEETCODE)

Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int length = s.length(); // Length of the String
        String visitedCharacters = ""; // Visited Characters will be appended in this Variable (SubString)

        int i = 0;
        int max = 0; // Length of the Longest Substring

        while (i < length) {
            char character01 = s.charAt(i);
            visitedCharacters = visitedCharacters + character01; // Character Appended
            int j = (i + 1);
            while (j < length) {
                char character02 = s.charAt(j);

                // Checking whether the Character is present in the Visited Characters or not
                if (visitedCharacters.indexOf(character02) == -1) {
                    visitedCharacters = visitedCharacters + character02; // Character Appended

                    //Checking Whether Inner Loop parsed throughout the Leftover String without any Repeatation 
                    if (j == (length - 1)) {
                        max = Math.max(max, visitedCharacters.length()); // Checking Maximum between Last Substring & recently created Substring
                        visitedCharacters = "";
                    }
                } else {
                    max = Math.max(max, visitedCharacters.length()); // Checking Maximum between Last Substring & recently created Substring
                    visitedCharacters = "";
                    break;
                }
                j++;
            }
            i++;
        }

        //Condition for the Single Character String
        if (i == 1) {
            max = 1;
        }

        return max;
    }
}
