//Name :- Pushkar Roy
//Date :- 05-10-2022

class Solution {
  public:
    //make function for check square or not
    bool judgeSquareSum(int c) {
      long long int l = 0;

      long long int r = sqrt(c);

    // check condition for loop

      while (l <= r) {

    // find range for checking

        long long int value = (l * l) + (r * r);

    // if value matchecd with given number return true

        if (value == c) {
          return true;
        }

    // if value greater than given number

        else if (value > c) {
          r--;
        }

    // if value less than given number

        else if (value < c) {
          l++;
        }
      }

   // if value not matched

      return false;
    }
};
