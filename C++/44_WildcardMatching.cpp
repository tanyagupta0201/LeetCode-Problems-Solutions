// Name: Laasya Gupta
// Date: 03/10/2022

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n1 = p.size();
        int n2 = s.size();

        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));

        // base case 1
        dp[0][0] = true;

        // base case 2
        // for any value of j, i is 0
        for (int j = 1; j < n2 + 1; j++)
            dp[0][j] = false;

        // base case 3
        for (int i = 1; i < n1 + 1; i++)
        {
            bool flag = true;

            for (int k = 1; k <= i; k++)
            {
                if (p[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }

            dp[i][0] = flag;
        }

        for (int i = 1; i < n1 + 1; i++)
        {
            for (int j = 1; j < n2 + 1; j++)
            {
                if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];

                else if (p[i - 1] == '*')
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];

                // if none of the case is found, we cannot match the strings
                else
                    dp[i][j] = false;
            }
        }

        return dp[n1][n2];
    }
};