// Name:Mahima Chauhan
// Date:15/10/2022
class Solution {
  public:
    // running dfs for island 1 to get the coordinates of all value of 1 together which they make an island.
    // storing them in vector of pairs with name land 1 for first island.
    void checkdfs1(int i, int j, vector < pair < int, int >> & land1, int m, int n, vector < vector < int >> & grid) {
      // if grid value is 0 or is out of bound of grid then return.
      if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) return;
      // after visiting make the value as 0.
      grid[i][j] = 0;
      // pushing the pair in land1 vector of pairs
      land1.push_back({
        i,
        j
      });
      checkdfs1(i + 1, j, land1, m, n, grid);
      checkdfs1(i - 1, j, land1, m, n, grid);
      checkdfs1(i, j + 1, land1, m, n, grid);
      checkdfs1(i, j - 1, land1, m, n, grid);
      return;
    }
  // running dfs for island 1 to get the coordinates of all value of 1 together which they make an island.
  // storing them in vector of pairs with name land 2 for first island.
  void checkdfs2(int i, int j, vector < pair < int, int >> & land2, int m, int n, vector < vector < int >> & grid) {
    // if grid value is 0 or is out of bound of grid then return.
    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) return;
    // after visiting make the value as 0.
    grid[i][j] = 0;
    // pushing the pair in land2 vector of pairs
    land2.push_back({
      i,
      j
    });
    checkdfs2(i + 1, j, land2, m, n, grid);
    checkdfs2(i - 1, j, land2, m, n, grid);
    checkdfs2(i, j + 1, land2, m, n, grid);
    checkdfs2(i, j - 1, land2, m, n, grid);
    return;
  }
  public:
    int shortestBridge(vector < vector < int >> & grid) {
      vector < pair < int, int >> land1; // vector of pair for storing all the coordinate for 1st island
      vector < pair < int, int >> land2; // vector of pair for storing all the coordinate for 2nd island
      int m = grid.size(); // row of grid
      int n = grid[0].size(); // column of grid
      int count = 0; // counter to count value of island
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (grid[i][j] == 1) {
            count++;
            if (count == 1) {
              checkdfs1(i, j, land1, m, n, grid); // dfs for first island
            } else if (count == 2) {
              checkdfs2(i, j, land2, m, n, grid); // dfs for second island
            }
          }

        }
      }
      // comparing the values for getting the minimal distance.
      int mini = INT_MAX; // to get smallest 0s to flip final result
      int ans = INT_MAX;
      for (int i = 0; i < land1.size(); i++) {
        for (int j = 0; j < land2.size(); j++) {
          ans = min((abs(land1[i].first - land2[j].first) + abs(land1[i].second - land2[j].second)) - 1, ans);
          if (ans < mini) {
            mini = ans;
          }
        }
      }
      return mini; // final answer return

    }
};