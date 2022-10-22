// Name: Simarprit Virdi
// Date: 13/10/2022

// There are many unnecessary repeated calculations in the brute-force approach. We can observe that the length of increasing subsequence starting at ith element with previously picked element prev will always be the same. So we can use dynamic programming to store the results for this state and reuse again in the future.

// But it wouldn't be scalable to store the state as (i, prev) because prev element can be any number in [-104, 104] meaning we would need to declare a matrix dp[n][1e8] which won't be possible

// DP with (i, prev) as state
// Instead, we could store the state of (i, prev_i), where prev_i denotes the index of previous chosen element. Thus we would use a dp matrix where dp[i][j] will denote the longest increasing subsequence from index i when previous chosen element's index is j.

class Solution {
    public:
        vector < vector < int >> dp;
    int lengthOfLIS(vector < int > & nums) {
        dp.resize(size(nums), vector < int > (1 + size(nums), -1)); // dp[i][j] denotes max LIS starting from i when nums[j] is previous picked element
        return solve(nums, 0, -1);
    }
    int solve(vector < int > & nums, int i, int prev_i) {
        if (i >= size(nums))
            return 0;
        if (dp[i][prev_i + 1] != -1)
            return dp[i][prev_i + 1];
        int take = 0, dontTake = solve(nums, i + 1, prev_i);
        if (prev_i == -1 || nums[i] > nums[prev_i])
            take = 1 + solve(nums, i + 1, i); // try picking current element if no previous element is chosen or current > nums[prev_i]
        return dp[i][prev_i + 1] = max(take, dontTake);
    }
};

// Time Complexity : O(N^2)
// Space Complexity : O(N^2)
