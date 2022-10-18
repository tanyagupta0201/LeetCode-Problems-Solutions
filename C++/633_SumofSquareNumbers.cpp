//Name :- Pushkar Roy
//Date :- 05-10-2022

class Solution {
  public:
    bool judgeSquareSum(int c) {
      long long int l = 0;

      long long int r = sqrt(c);
      while (l <= r) {
        long long int value = (l * l) + (r * r);
        if (value == c) {
          return true;
        } else if (value > c) {
          r--;
        } else if (value < c) {
          l++;
        }
      }
      return false;
    }
};
