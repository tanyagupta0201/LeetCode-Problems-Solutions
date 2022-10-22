// Name: Aditya Saha
// Date: 22/10/2022

// Problem:-

/*

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

Example:- 
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]] (Given in form of adjacency matrix)
Output: 2

*/

// Solution:-

/*

These problem can be solved using the concept of no. of connected component in a graph

*/

class Solution {
  // Dfs function to mark the node visited that are connected to it
  void dfs(vector < vector < int >> & isConnected, int i, vector < int > & visited, int n) {
    visited[i] = 1;
    for (int k = 0; k < n; k++) {
      if (isConnected[i][k] == 1 && visited[k] == 0) {
        dfs(isConnected, k, visited, n);
      }
    }
    return;
  }
  public:
    int findCircleNum(vector < vector < int >> & isConnected) {
      int n = isConnected.size();
      int ans = 0;
      vector < int > visited(n, 0);

      // Traverse each element in the adjacency matrix
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

          // check if the i-j is connected and it is not visited earlier
          // Then call dfs at the node i

          if (isConnected[i][j] == 1 && visited[i] == 0) {
            dfs(isConnected, i, visited, n);
            ans++; // Increament the count of connected component
          }
        }
      }
      return ans;
    }
};