// Name: Chamod Nugekotuwa
// Date: 17/10/2022

/* 
Problem Statement:

You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.

Example 1:

Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.

Example 2:

Input: stones = [1]
Output: 1

Implementation:

Consider sorting the array first inside each iteration - that means the two largest values in the array will always be;

x = array.length - 1 and y = array.length - 2

x will always be removed from the array regardless of x == to y or not. But when x != y, we must change the element at the last index (element at last index is y) to y - x 

Ultimately, the array will be reduced to only 1 element, and that will be our answer.
*/

class Solution {
    public int lastStoneWeight(int[] stones) {
        if (stones.length == 1)
            return stones[0];
        while (stones.length != 1) {
            Arrays.sort(stones);
            int x = stones[stones.length - 2], y = stones[stones.length - 1];
            stones = removeElement(stones, stones.length - 2);
            stones[stones.length - 1] = y - x;
        }
        return stones[0];
    }

    private int[] removeElement(int[] arr, int pos) {
        int[] res = new int[arr.length - 1];
        for (int i = 0, k = 0; i < arr.length; i++) {
            if (i != pos) {
                res[k] = arr[i];
                k++;
            }
        }
        return res;
    }
}