// Name: Shubham Kushwaha
// Date: 22 Oct, 2022

class Solution {
  public:
    void nextPermutation(vector <int> & nums) {
      int n = nums.size();
      int k;

      // Checking first greater number from the end

      for (k = n - 2; k >= 0; k--) {
        if (nums[k] < nums[k + 1])
          break;
      }

      int l;

      // if k<0 means the number is already sorted so we simply reverse if for next premutation

      if (k < 0) {
        reverse(nums.begin(), nums.end());
      } 
      // else find next greater number from the beginning.
      else {
        for (l = n - 1; l >= 0; l--) {
          if (nums[l] > nums[k])
            break;
        }

        // After finding both the points swap them 
 
        swap(nums[k], nums[l]);

        // Reverse the Number from the K+1 to the end
        
        reverse(nums.begin() + k + 1, nums.end());
      }

    }
};