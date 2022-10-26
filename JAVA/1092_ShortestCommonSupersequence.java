// Name : Nihar Vira
// Date : 26th October 2022

/* 

Problem Statement  
Given two strings X and Y, return the shortest string that has both str1 and str2 as subsequences. 
If there are multiple valid strings, return any of them 

Approach 
This is problem is similar to Longest Commom Subsequence (LCS) 
Firstly we will find all the character which are common in both string so that we can avoid multiples and minimize size of string

Time Complexity: O(N*M)
Reason: There are two nested loops

Space Complexity: O(N*M)
We are using an external array of size (N*M).

*/

class Solution {
  public String shortestCommonSupersequence(String X, String Y) {
    int n = X.length();
    int m = Y.length();

    // program to find LCS of two strings   
    int[][] t = new int[n + 1][m + 1];
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        t[i][j] = 0;
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        // if both the characters are equal then increment the count
        if (X.charAt(i - 1) == Y.charAt(j - 1)) {
          t[i][j] = 1 + t[i - 1][j - 1];
        } else {
          t[i][j] = Math.max(t[i - 1][j], t[i][j - 1]);
        }
      }
    }
    String a = "";
    int i = n;
    int j = m;
    // to find shortest common subsequence 
    while (i > 0 && j > 0) {
      // if both the characters are equal then include only once
      if (X.charAt(i - 1) == Y.charAt(j - 1)) {
        a = X.charAt(i - 1) + a;
        i--;
        j--;
      } else {
        // For non-lcs character we move the pointer to the top cell or left cell depending on which is greater. 
        // This way non-lcs characters will be included separately in the right order. 
        if (t[i][j - 1] > t[i - 1][j]) {
          a = Y.charAt(j - 1) + a;
          j--;
        } else {
          a = X.charAt(i - 1) + a;
          i--;
        }
      }
    }
    // if some characters are still left, then it must be also included
    while (i > 0) {
      a = X.charAt(i - 1) + a;
      i--;
    }
    while (j > 0) {
      a = Y.charAt(j - 1) + a;
      j--;
    }
    return a;
  }
}
