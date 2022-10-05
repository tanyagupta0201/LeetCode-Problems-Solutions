// Name: Naman Goyal
// Date: 4/10/2022

class Solution {
  public:
    int minCost(string colors, vector < int > & neededTime) {
      int n = colors.size();
      int ans = 0;
      // Iterating over the colors array and checking the equal colors values 
      for (int i = 0; i < n; i++) {
        int j = i;
        int sum = 0, ma = 0;
        while (j < n && colors[j] == colors[i]) {
          sum += neededTime[j];
          ma = max(ma, neededTime[j]);
          j++;
        }
        j--;
        // Finding the maximum value and subtracting it from the sum if no of same color values >= 2, taking only one value
        if (j - i + 1 >= 2) ans += sum - ma;
        i = j;
      }
      return ans;
    }
};
