// Name: Himanshu Singh
// Date: 04/10/2022

class Solution {
  public:
    int fn(string & text1, string & text2, int ind1, int ind2, vector < vector < int >> & dp) {
      if (ind1 < 0 || ind2 < 0) return 0;

      if (dp[ind1][ind2] != -1) return dp[ind1][ind2];
      if (text1[ind1] == text2[ind2]) return dp[ind1][ind2] = 1 + fn(text1, text2, ind1 - 1, ind2 - 1, dp);

      return dp[ind1][ind2] = max(fn(text1, text2, ind1 - 1, ind2, dp), fn(text1, text2, ind1, ind2 - 1, dp));
    }
  int longestCommonSubsequence(string text1, string text2) {
    int l1 = text1.length(), l2 = text2.length();
    vector < vector < int >> dp(l1, vector < int > (l2, -1));
    return fn(text1, text2, l1 - 1, l2 - 1, dp);
  }
};