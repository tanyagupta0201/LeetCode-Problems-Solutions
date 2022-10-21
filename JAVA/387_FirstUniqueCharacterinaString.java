// Name: Mohammad Mubaslat
// Date: 19/10/2022

// Given a string s, find the first non-repeating character in it and return its
// index. If it does not exist, return -1.

// Example 1:

// Input: s = "leetcode"
// Output: 0
// Example 2:

// Input: s = "loveleetcode"
// Output: 2
// Example 3:

// Input: s = "aabb"
// Output: -1

// Constraints:

// 1 <= s.length <= 105
// s consists of only lowercase English letters.

class Solution {
    public int firstUniqChar(String s) {
        Map<Character, Integer> myMap = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            if (myMap.containsKey(s.charAt(i)))
                myMap.put(s.charAt(i), myMap.get(s.charAt(i)) + 1);
            else
                myMap.put(s.charAt(i), 1);
        }

        for (int i = 0; i < s.length(); i++)
            if (myMap.get(s.charAt(i)) == 1)
                return i;

        return -1;

    }
}