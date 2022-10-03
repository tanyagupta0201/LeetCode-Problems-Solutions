// Name : Ashish Prasad Thakur
// Date : 4/10/2022

class Solution {
  public:
    int numDecodings(string s) {
      vector < int > dp(s.size() + 1, -1);
      return solve(s, s.size(), dp);

    }
  // recursive function with memoriozation
  int solve(string s, int i, vector < int > & dp) {
    if (s[0] == '0')
      return 0;

    if (i == 0 || i == 1)
      return 1;

    if (dp[i] != -1)
      return dp[i];

    int output = 0;

    if (s[i - 1] > '0')
      output += solve(s, i - 1, dp);

    if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7'))
      output += solve(s, i - 2, dp);

    return dp[i] = output;
  }
};