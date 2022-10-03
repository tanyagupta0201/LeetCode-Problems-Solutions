class Solution
{
public:
    // memoized solution
    int LCS(string &s1, string &s2, int m, int n, vector<vector<int>> &dp)
    {
        if (m == 0 || n == 0)
            return 0;
        if (dp[m][n] != -1)
            return dp[m][n];
        if (s1[m - 1] == s2[n - 1])
            return dp[m][n] = 1 + LCS(s1, s2, m - 1, n - 1, dp);
        else
            return dp[m][n] = max(LCS(s1, s2, m - 1, n, dp), LCS(s1, s2, m, n - 1, dp));
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return LCS(text1, text2, m, n, dp);
    }
};
// Code : Top Down DP(Tabulation)

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};