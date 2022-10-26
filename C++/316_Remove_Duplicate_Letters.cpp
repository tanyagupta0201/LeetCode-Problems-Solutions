// Name: Rajesh Sharma
// Date: 26/10/2022

/*
Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.
*/

// This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
// That is language variation.

/*
Approach: As the question suggests, We can greedily pick the characters which affect the answer
and can be picked in future where they may be coming after lower lexicographical characters.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
  public:
    string smallestSubsequence(string s) {
      vector < bool > vis(26, false); // visited array to mark if char already added to answer
      vector < int > lastOccurance(26, 1e5); // last occurance of each character is stored in this, useful to check if we can ignore this char now and pick it later
      for (int i = 0; i < s.length(); i++) lastOccurance[s[i] - 'a'] = i;
      stack < char > st; // stack to access previous character
      for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (vis[c - 'a']) continue;
        if (st.size() == 0) { // stack size is zero
          st.push(c);
          vis[c - 'a'] = true;
          continue;
        }

        while (st.size() && st.top() > c && lastOccurance[st.top() - 'a'] > i) { // while our previous character is > us and can be ignored right now, we pop it from the stack
          vis[st.top() - 'a'] = false;
          st.pop();
        }
        st.push(c);
        vis[c - 'a'] = true;
      }
      string ans = "";
      while (st.size()) { //fill stack chars in the answer string, note they will have to be reversed.
        ans.push_back(st.top());
        st.pop();
      }
      reverse(ans.begin(), ans.end()); // reversing
      return ans;
    }
};
