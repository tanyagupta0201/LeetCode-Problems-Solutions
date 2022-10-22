// Name: Mahima Chauhan
// Date: 21/10/2022
class Solution {
  public:
    int dfs(vector < vector < int >> & grid, int i, int j, vector < vector < bool >> & vis) {
      // If the value is out of bound or if it is already visited or if grid value is 0 then return 0.
      if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || vis[i][j] == true || grid[i][j] == 0)
        return 0;
      vis[i][j] = true; // after visiting mark value as true
      int curr = grid[i][j];
      // finding maximum value from all 4 directional grid cell value.
      curr = max({
        curr,
        grid[i][j] + dfs(grid, i - 1, j, vis),
        grid[i][j] + dfs(grid, i + 1, j, vis),
        grid[i][j] + dfs(grid, i, j - 1, vis),
        grid[i][j] + dfs(grid, i, j + 1, vis)
      });
      vis[i][j] = false; // after getting maximum result ,make that grid cell not visited.
      return curr; // return  maximum result
    }
  // Idea is that if grid cell value is not 0 then we will apply dfs from that cell to fetch maxmim gold that we can get and then update value of ans for every non zero grid cell
  int getMaximumGold(vector < vector < int >> & grid) {
    int ans = 0; // maximum amount of gold 
    int m = grid.size(); // rows of grid
    int n = grid[0].size(); // column of grid
    vector < vector < bool >> vis(m, vector < bool > (n, false));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] != 0) {
          int temp = dfs(grid, i, j, vis); // Applied dfs
          ans = max(ans, temp); // to store maximum answer
        }
      }
    }
    return ans;// return final answer
  }
};