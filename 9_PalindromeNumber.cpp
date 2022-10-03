// Name: Ishaan Sharma
// Date: 02/10/2022


class Solution {
  public:
    bool isPalindrome(int x) {
      int a = x;
      string str = to_string(a);
      int n = str.length();
      string strrr = str;
      for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
      if (str == strrr)
        return true;
      else
        return false;
    }
};
