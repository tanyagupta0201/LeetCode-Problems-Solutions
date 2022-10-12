// Name: Akshat Srivastava
// Date: 12-10-2022

class Solution {
  public:
    int largestPerimeter(vector < int > & nums) {

      //sort the array
      sort(nums.begin(), nums.end());

      //traverse from n-3 to 0
      for (int i = nums.size() - 3; i >= 0; i--) {

        //if at any instant a + b > c, return perimenter (a+b+c)
        if (nums[i] + nums[i + 1] > nums[i + 2]) {

          // a=nums[i], b=nums[i+1], c=nums[i+2];
          return nums[i] + nums[i + 1] + nums[i + 2];
        }
      }
      return 0; //else return 0
    }
};
