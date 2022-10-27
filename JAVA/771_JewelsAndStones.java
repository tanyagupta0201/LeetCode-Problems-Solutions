// Name: Vimu
// Date: 21/10/2022

/* 
You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: jewels = "aA", stones = "aAAbbbb"
Output: 3

Example 2:

Input: jewels = "z", stones = "ZZ"
Output: 0

Code Explanation:

We need a counter to increment when we find a jewel in our stones string.

We do this my looping through the characters of the stones and checking whether the same character exist in jewels string. If yes, we increment the jewelsFound variable by one.

Once the loop has exited, the variable jewelsFound will be the number of jewels that was found in the stones string.
*/

class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        int jewelsFound = 0;
        for (int i = 0; i < stones.length(); i++) {
            if (jewels.indexOf(stones.charAt(i)) != -1)
                jewelsFound++;
        }
        return jewelsFound;
    }
}