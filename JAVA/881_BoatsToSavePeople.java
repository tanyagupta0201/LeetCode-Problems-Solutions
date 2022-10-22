// Name: Chamod Nugekotuwa
// Date: 14/10/2022

/* 
Problem Statement:

You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

Example 1:

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)

Example 2:

Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)

Example 3:

Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
*/

import java.util.Arrays;

class Solution {
    public int numRescueBoats(int[] people, int limit) {
        int boatCount = 0;

        Arrays.sort(people);

        int lowerBoundary = 0;
        int upperBoundary = people.length - 1;

        // Using binary search method to find whether the sum of the lower bound and the
        // upper bound is equal to or is lower than the limit.
        // Since a boat can carry only two peope, the sum should be equal to their
        // weights.
        while (lowerBoundary <= upperBoundary) {
            if (people[lowerBoundary] + people[upperBoundary] <= limit)
                // By increasing the lower boundary (if the sum is lower or equal to the limit)
                // we eliminate that person since they can already be paired with another
                // person, to carry them in the boat.
                lowerBoundary++;
            // We disregard the last person anyway (the value at the index of upper
            // boundary) by decrementing the upper boundary since their weight is already
            // higher, which makes the sum of the two weights greater than the limit
            upperBoundary--;
            // Incrementing the count at each iteration, while lower boundary is equal to or
            // less than upper boundary, gives us the minimum number of boats required.
            boatCount++;
        }

        return boatCount;
    }
}