// Name: Mahima Chauhan
// Date: 22/10/2022
class Solution {
  public:
  int mod = 1e9 + 7;
  // Here basic idea is to use 3d dp bottom approach
  // As i,j and n is changing so create 3d dp with this parameters.
  long long unique_move(int i, int j, int n, vector < vector < vector < long long >>> & dp) {
    if (i < 0 || j < 0 || i > 3 || j > 2 || (i == 3 and j != 1)) return 0; // Basic conditions
    if (n == 1) return 1; // if n is 1 then as length is 1 return 1 only one value from that cell
    if (dp[i][j][n] != -1) return dp[i][j][n]; // dp conditions
    // Sum of all possible case then store it in dp[i][j][n]
    dp[i][j][n] = unique_move(i - 2, j - 1, n - 1, dp) % mod + unique_move(i - 2, j + 1, n - 1, dp) % mod +
      unique_move(i + 2, j - 1, n - 1, dp) % mod + unique_move(i + 2, j + 1, n - 1, dp) % mod +
      unique_move(i - 1, j - 2, n - 1, dp) % mod + unique_move(i - 1, j + 2, n - 1, dp) % mod +
      unique_move(i + 1, j - 2, n - 1, dp) % mod + unique_move(i + 1, j + 2, n - 1, dp) % mod;
    return dp[i][j][n]; // Return unique moves from that cell.
  }
  int knightDialer(int n) {
    int result = 0;
    vector < vector < vector < long long >>> dp(4, vector < vector < long long >> (3, vector < long long > (n + 1, -1)));
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 3; j++) {
        result = (result + unique_move(i, j, n, dp)) % mod; // summation of all uniue moves from each individual cells
      }
    }
    return result; // Final answers

  }

};