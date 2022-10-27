// Name: Kavindu Lakmal
// Date: 17/10/2022

/* 
Alice has n candies, where the ith candy is of type candyType[i]. Alice noticed that she started to gain weight, so she visited a doctor.

The doctor advised Alice to only eat n / 2 of the candies she has (n is always even). Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice.

Given the integer array candyType of length n, return the maximum number of different types of candies she can eat if she only eats n / 2 of them.

Example 1:

Input: candyType = [1,1,2,2,3,3]
Output: 3
Explanation: Alice can only eat 6 / 2 = 3 candies. Since there are only 3 types, she can eat one of each type.

Example 2:

Input: candyType = [1,1,2,3]
Output: 2
Explanation: Alice can only eat 4 / 2 = 2 candies. Whether she eats types [1,2], [1,3], or [2,3], she still can only eat 2 different types.

Example 3:

Input: candyType = [6,6,6,6]
Output: 1
Explanation: Alice can only eat 4 / 2 = 2 candies. Even though she can eat 2 candies, she only has 1 type.

Implementation:

We reduce the array to have no duplicate values, thus providing us with an array with unique values.

A HashSet is used to contain unique values, that is it doesn't allow duplicate values in the array.

The length of this array can be used to check whether the amount of candy, which is array length / 2 is lower or higher than the array with unique candy types.

If it's higher, the total  of candy that can be eaten will be array.length / 2, if it's lower, it will be length of the array with no duplicates.
*/

class Solution {
    public int distributeCandies(int[] candyType) {
        Set<Integer> set = new HashSet<Integer>();
        for (int num : candyType) {
            set.add(num);
        }
        int total = set.size();
        int max = candyType.length / 2;
        if(total > max) {
            total = max;
        }
        return total;
    }
}