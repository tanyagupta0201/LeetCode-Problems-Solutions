// Name: Mahima Chauhan
// Date: 21/10/2022
// considering 4 cases
// 1-> dp[i]+=dp[i-2] ,j={1,i-2}
// 2->dp[i]+=dp[i-3]*2,jj={1,i-3}
// 3->dp[i]+=dp[i-4]*2...and so on
// and same if it is i-1
// we get two equations and by equating them we get 
// dp[i]=2*dp[i-1]+dp[i-3]
class Solution {
  public:
    int numTilings(int n) {
      int mod = 1e9 + 7;
      vector < long long > dp(1001, 0);
      dp[1] = 1; // base cases
      dp[2] = 2;
      dp[3] = 5;
      if (n <= 3) return dp[n];
      for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 1] + dp[i - 3]; // applying formula
        dp[i] %= mod; // modulo by mod
      }
      return dp[n]; // return dp.back() as answer

    }
};