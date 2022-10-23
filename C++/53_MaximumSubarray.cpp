// Name: Shubham Kushwaha
// Date: 22 Oct, 2022


class Solution {
  public:
    int maxSubArray(vector <int> &nums) {
      int sum = 0, ans = INT_MIN;

      // We take two variables sum and ans
      // sum store the sum value from the beginning of the array 
      // And ans stores the maximum sum value

      for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        ans = max(ans, sum);

        // if sum became less then 0, so assign sum as 0
        // Because we want to find the maximum sum  
        if (sum < 0)
          sum = 0;
      }

      // Finally we return ans as a result. 
      return ans;
    }
};
