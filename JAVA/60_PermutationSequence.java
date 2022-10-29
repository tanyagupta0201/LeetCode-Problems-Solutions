// Name : Abhay Jagtap
// Date : 29/10/2022

/*
Problem :
The set [1, 2, 3, ..., n] contains a total of n! unique permutations. By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Example 1 :
Input: n = 3, k = 3
Output: "213"

Example 2 :
Input: n = 4, k = 9
Output: "2314"

Time Complexity : O(n)
Space Complexity : O(n)
*/

class Solution {
  public String getPermutation(int n, int k) {
    ArrayList number = new ArrayList < > ();
    String ans = "";
    int fact = 1;
    for (int i = 1; i < n; i++) {
      fact = fact * i;
      number.add(i);
    }
    number.add(n); //we do not n as we have to calculate factorial for n-1 numbers as there 1 digit is already placed at its position
    k = k - 1; //as we are using 0 bit indexing(starting from 0 rather than 1)
    while (true) {
      ans = ans + number.get(k / fact); // k/fact is the digits that is required to be placed according to given k
      number.remove(k / fact);
      if (number.size() == 0) //no digits left to place them in the places.
        break;

      k = k % fact; //
      fact = fact / number.size(); // as number.size()has decreased by 1 we require factorial of 1 less number of digits like if there fact was 6 that meant there were three digits for permutation so when we select either the three then there will remain two digits for further proceedings so 2! = 2  (so 6/3=2 therefore 3 is the size of new number arrayList and there is first place that is already occupied. )
    }
    return ans;
  }
}
