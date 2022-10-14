/*NAME: Chandan Sahu
DATE: 14/10/2022

The problem can be recursively defined by:

power(x, n) = power(x, n / 2) * power(x, n / 2);        // if n is even
power(x, n) = x * power(x, n / 2) * power(x, n / 2);    // if n is odd
*/

class Solution {

  public:

    double myPow(double x, int n) {

      // If x^0 return 1

      if (n == 0) {

        return 1;

      }
      // if n is negative

      if (n < 0) {

        n = abs(n);

        x = 1 / x;

      }
      //if n is even
      if (n % 2 == 0) {

        return myPow(x * x, n / 2);

      } // if n is odd 
      else {

        return x * myPow(x * x, n / 2);

      }

    }

};
