// Name : Karthik S
// Date : 06 October 2022

class Solution {
  public:
    int largestRectangleArea(vector < int > & heights) {

      // Create Monotonically Increasing Stack
      stack < pair < int, int >> stk;
      int result = 0;

      // Calculate Area between each height
      for (int i = 0; i < heights.size(); i++) {
        int start = i;
        while (!stk.empty() && stk.top().second > heights[i]) {
          int index = stk.top().first;
          int width = i - index;
          int height = stk.top().second;
          stk.pop();

          result = max(result, height * width);
          start = index;
        }
        stk.push({
          start,
          heights[i]
        });
      }

      // Popping the stack if it's not empty
      while (!stk.empty()) {
        int width = heights.size() - stk.top().first;
        int height = stk.top().second;
        stk.pop();

        result = max(result, height * width);
      }

      return result;
    }
};
