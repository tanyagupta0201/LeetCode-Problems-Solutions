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
        int length = s.length();
        String visitedCharacters = "";

        int i = 0;
        int max = 0;

        while (i < length) {
            char character01 = s.charAt(i);
            visitedCharacters = visitedCharacters + character01;
            int j = (i + 1);
            while (j < length) {
                char character02 = s.charAt(j);
                if (visitedCharacters.indexOf(character02) == -1) {
                    visitedCharacters = visitedCharacters + character02;
                    if (j == (length - 1)) {
                        max = Math.max(max, visitedCharacters.length());
                        visitedCharacters = "";
                    }
                } else {
                    max = Math.max(max, visitedCharacters.length());
                    visitedCharacters = "";
                    break;
                }
                j++;
            }
            i++;
        }

        if (i == 1) {
            max = 1;
        }

        return max;
    }
}