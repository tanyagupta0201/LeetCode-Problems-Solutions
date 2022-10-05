// Name: Himanshu Singh
// Date: 5/10/2022


//This problem is the classic dp on strings problem
class Solution {
  public:

    // Basically what we have to do is we are given two strings and we have to return longest common subsequence length of these strings
    // Subsequence:- A subsequece is the sequece which can be at any position but the order should be maintained
    // e.g  For abc - [a, ab, ac, abc] are the subsequences

    int longestCommonSubsequence(string text1, string text2) {
      int n = text1.length(), m = text2.length();

      // We are making a dp array dp[s1.length+1][s2.length+1]

      vector < vector < int >> dp(n + 1, vector < int > (m + 1, 0));

      // The base cases are if the pointers are at the position less than the first character than it will not be counted towards the length
      // As the we have precomputed the base cases so using these base cases we can deduce future values
      for (int i = 0; i <= m; i++) dp[0][i] = 0;
      for (int i = 0; i <= n; i++) dp[i][0] = 0;

      // Here it intuition is if text1[ind1]==text2[ind2] the we have a common subsequnce, we will increment the answer and then check for one index less for both the strings
      //If the characters won't match then we will check either for text1[ind-1] or for text2[ind2-1] and we will return the maximum of them as we have to find longest of them
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
          else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
      return dp[n][m];
    }
};