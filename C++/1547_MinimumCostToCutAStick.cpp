// Name: Himanshu Singh
// Date: 05/10/2022

// This is the problem of partition dp topic
// Basically what we have to do is we are given a stick of length n and a cuts array we have to cut our stick in such a way that we would get the minimum cost
class Solution {
  public:
    int fn(int i, int j, vector < int > & cuts, vector < vector < int >> & dp) {
      if (i > j) return 0; // Base case whenever the ith pointer crosses jth we won't be able to cut the rod 
      if (dp[i][j] != -1) return dp[i][j];
      int mini = 1e9;

      // This for loop will help us to partition our cuts array and calculate the answer of each subproblem
      for (int ind = i; ind <= j; ind++) {
        // As our pointers are at i, j so the cost of the cutting at each step will be cuts[i-1]-cuts[j-1]
        int cost = cuts[j + 1] - cuts[i - 1] + fn(i, ind - 1, cuts, dp) + fn(ind + 1, j, cuts, dp); // we are calling two recursive functions, these functions will help us to partition our array as first function will partition from i to ind-1 and other will partition from ind+1 to j

        mini = min(mini, cost); // As we have to find the minimum cost so we will take the minimum cost of that partition
      }
      return dp[i][j] = mini;
    }

  int minCost(int n, vector < int > & cuts) {
    int size = cuts.size();

    //initialy we will add 0 the begin and n(length of rod) to the end in the cuts array this is because we have to calculate the cost and for first cut the cost will be n-0
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);

    // We need to sort the cuts array because by sorting the cuts array we can independently compute the cost for each subproblem
    sort(cuts.begin(), cuts.end());
    vector < vector < int >> dp(size + 2, vector < int > (size + 2, 0));

    return fn(1, size, cuts, dp);
  }
};