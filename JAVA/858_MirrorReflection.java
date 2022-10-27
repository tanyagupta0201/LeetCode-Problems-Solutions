// Name: Abuzar Bagewadi
// Contributed Date: 19/10/2022

/*

-> We use extended blocks to simulate the reflection.
-> As well as the reflection of the corners 0, 1, 2.
-> Then the laser could go straightly to the top right of the extending blocks until it reaches any of the corners.
-> Then we can use p/q to represents the extending blocks x/y ratio which is 5/2 in the example above.
-> Then the destination corner could be calculated using this x/y ratio.
-> We used modulo 2 is that if x/y=10/4 for example, the laser will firstly reach the corner 0 when x/y=5/2 before x/y=10/4. You can draw a similar graph to simulate it.
-> So, when the laser first reaches a corner, the x and y cannot both be even. So we keep using modulo 2 to let x and y go down.

*/

class Solution {
  public int mirrorReflection(int p, int q) {

    // use extending the mirror method to see where the ray meets a corner
    // you will find a pattern
    while (p % 2 == 0 && q % 2 == 0) {
      p /= 2;
      q /= 2;
    }
    // case 1: if p is even
    if (p % 2 == 0) {
      return 2;
    }
    // case 2: if q is even
    else if (q % 2 == 0) {
      return 0;
    }
    // case 3: if both are odd
    else {
      return 1;
    }
  }
}