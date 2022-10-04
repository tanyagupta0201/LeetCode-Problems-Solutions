/* 
   Author Name: Tasmiya Khan
   Date: 3 October 2022
*/

class Solution {
  public:
    bool isValid(string s) {
      stack < char > st;
      bool ans = true;

      for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
          st.push(s[i]);
        } else if (s[i] == ')') {
          if (!st.empty() && st.top() == '(') {
            st.pop();
          } else {
            return false;
            break;
          }
        } else if (s[i] == ']') {
          if (!st.empty() && st.top() == '[') {
            st.pop();
          } else {
            return false;
            break;
          }
        } else if (s[i] == '}') {
          if (!st.empty() && st.top() == '{') {
            st.pop();
          } else {
            return false;
            break;
          }

        }
      }
      if (!st.empty()) {
        return false;
      } else {
        return true;
      }

    }
};