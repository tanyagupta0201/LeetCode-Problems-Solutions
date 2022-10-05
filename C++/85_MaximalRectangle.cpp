// Name: Naman Goyal
// Date: 05/10/2022

class Solution {
  public:
    int maximalRectangle(vector < vector < char >> & matrix) {
      int rows = matrix.size();
      if (rows == 0) return 0;
      int cols = matrix[0].size();
      int sum[rows][cols];
      // Storing the prefix sums if values == '1' then add previous sum else 0
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          if (matrix[i][j] == '1') {
            if (i - 1 >= 0)
              sum[i][j] = sum[i - 1][j] + 1;
            else
              sum[i][j] = 1;
          } else
            sum[i][j] = 0;
        }
      }

      int ans = 0;
      for (int i = 0; i < rows; i++) {
        // Store all the values in heights array which shows how many consecutive ones are down from the (i,j)th position
        vector < int > heights;
        for (int j = 0; j < cols; j++)
          heights.push_back(sum[i][j]);
        int n = heights.size();
        stack < int > s;
        int right[n], left[n];
        // Calculating the next greater and previous greater element using the stack method
        for (int i = 0; i < n; i++) {
          while (!s.empty() && heights[s.top()] > heights[i]) {
            right[s.top()] = i;
            s.pop();
          }
          s.push(i);
        }

        while (!s.empty()) {
          right[s.top()] = n;
          s.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
          while (!s.empty() && heights[s.top()] > heights[i]) {
            left[s.top()] = i;
            s.pop();
          }
          s.push(i);
        }
        while (!s.empty()) {
          left[s.top()] = -1;
          s.pop();
        }
        int maxi = INT_MIN;
        // Calculating max rectangle of '1' formed from (i,j) position
        for (int i = 0; i < n; i++) {
          maxi = max(maxi, heights[i] * ((right[i] - left[i]) - 1));
        }
        ans = max(ans, maxi);
      }

      return ans;
    }
};
