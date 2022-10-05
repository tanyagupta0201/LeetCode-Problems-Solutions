// Name: Kumar Shanu
// Date: 05/10/2022



// This version of code is space optimised and only two variable are used
// prev2 and prev in place of whole array
// It is a better version of memoisation.

class Solution {
    public int rob(int[] nums) {

        int len = nums.length;
        int prev2 = 0, prev = 0;

        for (int i = 0; i < len; i++) {

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
}
