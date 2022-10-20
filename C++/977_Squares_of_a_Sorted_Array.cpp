// Name: Surbhi Sawan
// Date: 20/10/2022

class Solution {
  public:
    vector < int > sortedSquares(vector < int > & nums) {
      int n = nums.size(); // size of a vector array

      //for loop to traverse the vector array
      for (int i = 0; i < n; i++) {
        nums[i] = pow(nums[i], 2); //to find the square of the element of the vector array
      }

      //sort the nums array 
      sort(nums.begin(), nums.end());
      return nums;  //return the resultant vector
    }
};
