// Name: Kumar Shanu
// Date: 05/10/2022


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
