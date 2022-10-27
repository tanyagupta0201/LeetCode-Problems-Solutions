// Name : Nihar Vira
// Date : 19th October 2022

// without the need for any kind of backtracking, we resolve this issue using greedy approach in O(N) time complexity.
class Solution {
  public int longestValidParentheses(String s) {
    int c = 0;
    // initialized an empty stack 
    Stack <Integer> st = new Stack <>();
    st.push(-1);
    // we iterate through the string
    for (int i = 0; i < s.length(); i++) {
      /* if '(' is found, we append index of our character 
      so that we can easily find the difference between the ')' at i and the last entry in the stack*/
      if (s.charAt(i) == '(') {
        st.push(i);
      } else {
        st.pop();
        if (!st.isEmpty()) {
          c = Math.max(c, i - st.peek());
        } else {
          st.push(i);
        }
      }
    }
    return c;

  }
}
