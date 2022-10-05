// Name: Himanshu Singh
// Date: 04/10/2022

class Solution {
  public:
    bool canPartition(vector < int > & nums) {

      int sum = 0;
      for (auto x: nums) {
        sum += x;
      }
      // We will check weather the sum of the elements of array is odd or not. If odd then we can't partition our array and return false
      if (sum % 2) return false;

      // Then we will divide our sum into two equal part and check for other if sum/2 exists then other part is bound to exist.
      sum = sum / 2;

      // Now we will write the tabulation solution of this problem by making a dp array. Using this dp we will use the precomputed values
      vector < vector < bool >> dp(nums.size(), vector < bool > (sum + 1, 0));

      for (int ind = 0; ind < nums.size(); ind++) { // This is the base case, no matter is which index we are at if the targetsum becomes zero that means the targetsum exists 
        dp[ind][0] = true;
      }
      if (sum >= nums[0]) dp[0][nums[0]] = true; // At dp[0][0] if the sum is zero than we can also partition our array at that point

      // Then we just have to write the tabulation code by the concept of pick not pick, we will pick only if the our targetSum is greater than the the number at that index
      for (int ind = 1; ind < nums.size(); ind++) {
        for (int tar = 1; tar <= sum; tar++) {
          bool notPick = dp[ind - 1][tar];
          bool pick = false;
          if (tar >= nums[ind])
            pick = dp[ind - 1][tar - nums[ind]];
          dp[ind][tar] = pick | notPick; // If we get true either by picking or not picking we will make that position true;
        }
      }
      return dp[nums.size() - 1][sum]; // At dp[n-1][sum] we will have the answer that weater we can partition or not our array
    }
};