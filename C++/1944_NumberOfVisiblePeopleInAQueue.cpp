// Name : Karthik S
// Date : 03 October 2022

// Link to Question
// https://leetcode.com/problems/number-of-visible-people-in-a-queue/

class Solution {
  public:
    vector < int > canSeePersonsCount(vector < int > & heights) {
      int n = heights.size();
      vector < int > res(n, 0);

      stack < int > stk;

      for (int i = n - 1; i >= 0; i--) {
        int height = heights[i];
        int visible = 0;

        while (!stk.empty() && height > stk.top()) {
          visible += 1;
          stk.pop();
        }

        if (!stk.empty()) {
          visible += 1;
        }
        res[i] = visible;
        stk.push(height);
      }
      return res;
    }
};
