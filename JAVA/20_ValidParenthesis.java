//   Name: Madhu Saini
//   Date: 04/10/22
import java.util.*;
class Solution {
  public boolean isValid(String s) {
    if (s.length() % 2 != 0) {
      return false;
    }

    Stack < Character > stack = new Stack < > ();

    for (int i = 0; i < s.length(); i++) {
      char c = s.charAt(i);
      if (c == '(' || c == '{' || c == '[') {
        stack.push(c);
      } else {
        if (stack.isEmpty())
          return false;
        if (c == ')' && stack.peek() == '(' ||
          c == '}' && stack.peek() == '{' ||
          c == ']' && stack.peek() == '[')

          stack.pop();
        else
          return false;
      }

    }
    return stack.isEmpty();
  }
}
