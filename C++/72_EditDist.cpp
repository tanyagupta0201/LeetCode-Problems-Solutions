// Name-:Jai Sinha
// Edited on-:03/10/2022

/** Edit Distance
  * Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
  * You have the following three operations permitted on a word:
* Insert a character
* Delete a character
* Replace a character

 * Example

 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation: 
* horse -> rorse (replace 'h' with 'r')
*rorse -> rose (remove 'r')
* rose -> ros (remove 'e')

**/

#include <bits/stdc++.h>   //contains all the header files
using namespace std;
int editDistance(string str1, string str2) {
  //doing space optimization             //Time Complexity = O(n*m)
  int n = str1.length(); //Space Complexity = O(n+m)
  int m = str2.length();
  vector < int > pre(m + 1, 0); //creating a pre vector
  for (int i = 0; i <= m; i++)
    pre[i] = i; //initializing the pre vector by its own index
  for (int i = 1; i <= n; i++) {
    vector < int > temp(m + 1, 0); //making a temperorary vector
    temp[0] = i;
    for (int j = 1; j <= m; j++) {
      if (str1[i - 1] == str2[j - 1]) //if the previous elements are equal
        temp[j] = pre[j - 1];
      else
        temp[j] = 1 + min(pre[j], min(temp[j - 1], pre[j - 1])); //else store the minimum of the elements
    }
    pre = temp; //previous vector becomes temp vector
  }
  return pre[m];
}
int main() {
  string s1;
  cin >> s1;
  string s2;
  cin >> s2;
  cout << editDistance(s1, s2); //calling function
}
