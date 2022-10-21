// Name: Souvik Sen
// Date: 20/10/2022

/*
You are given an array nums consisting of positive integers.

We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.

Return the length of the longest nice subarray.

A subarray is a contiguous part of an array.

Note that subarrays of length 1 are always considered nice.

*/

// using sliding window of variable length
// we have to find the maximum window size

class Solution {
   public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 1;
        int ans = 1;
        long long curOR = nums[0];
        while (j < n) {
            // if the AND of the numbers is 0, keep on setting the bits for that position in curOR
            if ((curOR & nums[j]) == 0) {
                curOR |= nums[j];
            } else {
                // if at any point a single position has more than 1 set bit
                while (i != j && ((curOR & nums[j]) != 0)) {
                    // unset the bits at that position until AND of the two is not equal to zero(0) again
                    curOR ^= nums[i];
                    // increament the starting index of the window
                    i++;
                }
                curOR |= nums[j];
            }
            // keep count of the maximum window size
            ans = max(ans, j - i + 1);
            j++;
        }
        // return maximum window size
        return ans;
    }
};