// Name: Sandaruwan
// Date: 31/10/2022

/* 
Problem Statement:

A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right.

Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM), return all possible times the watch could represent. You may return the answer in any order.

The hour must not contain a leading zero.

For example, "01:00" is not valid. It should be "1:00".
The minute must be consist of two digits and may contain a leading zero.

For example, "10:2" is not valid. It should be "10:02".

Example 1:

Input: turnedOn = 1
Output: ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]

Example 2:

Input: turnedOn = 9
Output: []

Implementation:

This is fairly easy to understand - we use two for loops that iterates hour count and minute count. Now for each hour and minute, we can get its binary representation, get the count of 1's bits and compare whether the count is equal to the turnedOn value.

If it does, we can add that specific time, h:mm to our list. If the minute value is less than ten, we need to add a leading zero. A StringBuilder is used since we can manipulate the characters and create a string to our wish.

Finally, after all matching 1's bit counts have been found, we can return the list, which will be our output.
*/

class Solution {
    public List<String> readBinaryWatch(int turnedOn) {
        List<String> poss = new ArrayList();

        for (int hour = 0; hour < 12; hour++) {
            for (int minute = 0; minute < 60; minute++) {
                if (bitCount(hour, minute, turnedOn)) {
                    StringBuilder time = new StringBuilder();
                    time.append(hour).append(":");
                    if (minute < 10) {
                        time.append("0");
                    }
                    time.append(minute);
                    poss.add(time.toString());
                }
            }
        }
        return poss;
    }

    public static boolean bitCount(int h, int m, int key) {
        return bitCount(Integer.toBinaryString(h)) + bitCount(Integer.toBinaryString(m)) == key;
    }

    public static int bitCount(String v) {
        int count = 0;
        for (int i = 0; i < v.length(); i++) {
            if (v.charAt(i) == '1') {
                count++;
            }
        }
        return count;
    }
}