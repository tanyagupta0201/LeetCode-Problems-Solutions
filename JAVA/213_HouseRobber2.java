// Name: Kumar Shanu
// Date: 05/10/2022



// This problem is similar to the house robber problem 
// link to house robber: https://github.com/tanyagupta0201/LeetCode-Problems-Solutions/blob/main/JAVA/198_HouseRobber.java
// The difference here is that, we need to understand that we cannot access the first and the last simultaneously.
// If we are starting from the first then we need to exclude the last house.
// And if we are starting from the last house then we need to exclude the first house respectively.

// The best idea in this case is to find solution in both the case and return the solution which has maximum.

// In order to find the solution we are taking help of tabulation method.
// In a function we are asking for the starting point.
// If the starting point is 0 index then we are taking the first house and excluding the last and for starting point 1 vice versa.
// We are using one condition, if we are taking the first house then we are adding it in the take(variable) and moving to other index
// and if we are not taking the value then we are adding 0, going from starting index to end and returning the sum.

// Finally in the main function we are comparing both the result and returning the max.

class Solution {

    public static int houseRobber1(int start, int end, int nums[]) {

        int len = nums.length;
        int prev2 = 0, prev = 0;

        for (int i = start; i < end; i++) {

            int take = nums[i], notTake = 0;

            if (i > 1)
                take += prev2;

            if (i > 0)
                notTake = prev;

            int curr = Math.max(take, notTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    public int rob(int[] nums) {

        if (nums.length == 1)
            return nums[0];

        int len = nums.length;
        int first = houseRobber1(1, len, nums);
        int second = houseRobber1(0, len - 1, nums);
        return Math.max(first, second);

    }
}
