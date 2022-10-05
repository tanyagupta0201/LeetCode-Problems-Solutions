// Name: Garvit Agarwal
//Date: 05/10/2022

class Solution {
  public:
    int hammingWeight(uint32_t n) {
      int count = 0;
      while (n > 0) {
        //Checking  last digit is 1 or not
        if (n & 1) {
          count++;
        }
        // Right Shift Operator
        n = n >> 1;
      }
      return count;
    }
};
