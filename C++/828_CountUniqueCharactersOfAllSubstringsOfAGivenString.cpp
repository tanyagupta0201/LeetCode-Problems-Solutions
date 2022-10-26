// Name: Rajesh Sharma
// Date: 26/10/2022
/*
Let's define a function countUniqueChars(s) that returns the number of unique characters on s.

For example, calling countUniqueChars(s) if s = "LEETCODE" then "L", "T", "C", "O", "D" are the unique characters since they appear only once in s,
therefore countUniqueChars(s) = 5. Given a string s, return the sum of countUniqueChars(t) where t is a substring of s.
The test cases are generated such that the answer fits in a 32-bit integer.

Notice that some substrings can be repeated so in this case you have to count the repeated ones too.
*/

/*
Approach : Instead of counting the number of unique characters in each substring, think of it like how much would a particular
character would contribute to the final answer. If the character is repeated in the string, calculate the max size of substring
which ends on it and which starts on it, without having multiple instances. Once you get the sizes, simple multiply the sizes,
look at this multiplication operation as a join operation.

Time complexity : O(n)
Space Complexity: O(n)

*/

class Solution {
  public:
    int uniqueLetterString(string s) {

      vector < vector < int >> arr(26, vector < int > ()); // Each character's occurance index will be stored here
      for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        arr[c - 'A'].push_back(i);
      }

      int ans = 0;
      for (auto & v: arr) {
        for (int i = 0; i < v.size(); i++) { // Iterating over each instance
          int prev = i == 0 ? 0 : v[i - 1] + 1;
          int next = i == v.size() - 1 ? s.length() - 1 : v[i + 1] - 1;
          int leftWindow = v[i] - prev + 1; // Size of substring ending on the index
          int rightWindow = next - v[i] + 1; // Size of substring starting on the index
          ans += leftWindow * rightWindow; // Doing the "Join" operation
        }
      }
      return ans;
    }
};
