# NAME : Shubham Arora
# Date : 23/Oct/2022


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        # finding the length of both the string
        m = len(s)
        n = len(p)
        # checking initial edge condition
        if p == "*":
            return True
        # Creating a table and initialising the first entry
        dp = [[0 for i in range(n + 1)] for j in range(m + 1)]
        dp[0][0] = 1
        for i in range(1, n + 1):
            # checking condition for the '*'
            if p[i - 1] == "*":
                dp[0][i] = 1
            else:
                break
        # creating a function for checking all the necessary cases
        def matching(s, p, m, n):
            for i in range(1, m + 1):
                for j in range(1, n + 1):
                    if s[i - 1] == p[j - 1]:
                        dp[i][j] = dp[i - 1][j - 1]
                    elif p[j - 1] == "?":
                        dp[i][j] = dp[i - 1][j - 1]
                    elif p[j - 1] == "*":
                        dp[i][j] = dp[i - 1][j - 1] or dp[i - 1][j] or dp[i][j - 1]
            return dp[m][n]

        # returning the final output
        w = matching(s, p, m, n)
        if w:
            return True
        else:
            return False
