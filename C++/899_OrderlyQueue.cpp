// Name: Rohan Sharma
// Date: 22/10/2022

// You are given a string s and an integer k.
// You can choose one of the first k letters of s and append it at the end of the string..
// Return the lexicographically smallest string you could have after applying the mentioned step any number of moves.

// Approach: For k == 1, the case can be handled by making all the permutations and returning the smallest one,
// for k>1, is you analyze different test cases, you can realise that any position can be replaced by the other and the special queue also follows bubble sort algo.
// This you can simply sort the string and return the sorted string.

class Solution {
  public:
    string orderlyQueue(string s, int k) {
      if (k == 1) {
        set < string > st;
        while (true) {
          if (st.find(s) != st.end()) break;
          st.insert(s);
          s = s.substr(1) + s[0];
        }
        return *st.begin();
      }
      sort(s.begin(), s.end());
      return s;
    }
};
