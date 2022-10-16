// Name: Himanshu M
// Date: 16-10-2022

/* Logic -
    1. Using bfs we can traverse in levels. So, at each level store pair{val, col} 
       of all nodes in that level. Sort the vector by val
    2. Traverse from first level to last level and access the above sorted vector.
    3. Make a map which has key as columns(col) and value as vector of vals
    4. From each row, convert {val, col} ==> map[col].push_back(val)
*/
class Solution {
  public:
    map < int, vector < int >> col;
  void bfs(TreeNode * root, pair < int, int > p) {
    // for root
    col[0].push_back(root -> val);
    queue < pair < TreeNode * , pair < int, int > >> q;
    q.push({
      root,
      p
    });

    map < int, vector < pair < int, int >>> mp;
    while (!q.empty()) {
      auto x = q.front();
      q.pop();
      int xc, yc;
      xc = x.second.first + 1;
      if (x.first -> left) {
        yc = x.second.second - 1;
        mp[xc].push_back({
          x.first -> left -> val,
          yc
        });
        q.push({
          x.first -> left,
          {
            xc,
            yc
          }
        });
      }
      if (x.first -> right) {
        yc = x.second.second + 1;
        mp[xc].push_back({
          x.first -> right -> val,
          yc
        });
        q.push({
          x.first -> right,
          {
            xc,
            yc
          }
        });
      }
    }
    // sorting vector and pushing in map
    for (auto m: mp) {
      auto v = m.second;
      sort(v.begin(), v.end());

      for (auto t: v) {
        col[t.second].push_back(t.first);
      }
    }
  }
  vector < vector < int >> verticalTraversal(TreeNode * root) {
    bfs(root, {
      0,
      0
    });
    vector < vector < int >> ans;
    for (auto x: col) {
      ans.push_back(x.second);
    }
    return ans;
  }
};