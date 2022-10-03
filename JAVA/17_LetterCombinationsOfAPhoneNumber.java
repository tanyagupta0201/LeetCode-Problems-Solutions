// Name: Aneesh Gupta
// Date: 3/10/2022

/*Problem
17. Letter Combinations of a Phone Number (LEETCODE)
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Meaning -> For example, if we have "23" as the input string, then the possible mappings are -> "ad","ae","af","bd","be","bf","cd","ce","cf"
How to implement -> We'll be using recursive approach to solve this problem. 

IDEOLOGY -> According to the given example, first get the list of all mappings for "3", i.e. ["d", "e", "f"], Now pick up each character corresponding to "2" 
and add that character in the front of each obtained string above. Hence we get -> ["ad","ae","af","bd","be","bf","cd","ce","cf"] */

class Solution {
  static String[] codes = { //This array contains corresponding mappings
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
  };
  public List < String > letterCombinations(String digits) {

    if (digits.length() == 0) { // base case in recursion 
      List < String > bres = new ArrayList < > ();
      return bres;
    }

    char ch = digits.charAt(0);
    String rques = digits.substring(1);

    //getting recursive solution -> here, we'll get all the combinations correspinding to the string obtained if it's first character is removed. 
    List < String > rres = letterCombinations(rques);
    if (rres.size() == 0) {
      rres.add("");
    }

    //now getting codes for the digit pressed
    String code = codes[ch - '0'];
    List < String > ans = new ArrayList < > ();
    for (int i = 0; i < code.length(); i++) {
      char ch1 = code.charAt(i);
      for (String val: rres) {
        ans.add(ch1 + val);
      }
    }
    return ans;
  }
}
