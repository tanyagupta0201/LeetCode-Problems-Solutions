// Name:- Nandini Srivastava.
// Date:- 25/10/2022

/*
 * 
 * leetcode problem No. - 932. Beautiful Array
 * 
 * An array nums of length n is beautiful if:

nums is a permutation of the integers in the range [1, n].
For every 0 <= i < j < n, there is no index k with i < k < j where 2 * nums[k] == nums[i] + nums[j].
Given the integer n, return any beautiful array nums of length n. There will be at least one valid answer for the given n.

 

Example 1:

Input: n = 4
Output: [2,1,4,3]
Example 2:

Input: n = 5
Output: [3,1,2,5,4]
 

Constraints:

1 <= n <= 1000

 */

 // Solution 

  class Solution {
   Map < Integer, int[] > memo;
   public int[] beautifulArray(int N) {
     memo = new HashMap();
     return f(N);
   }

   public int[] f(int N) {
     if (memo.containsKey(N))
       return memo.get(N);

     int[] ans = new int[N];
     if (N == 1) {
       ans[0] = 1;
     } else {
       int t = 0;
       for (int x: f((N + 1) / 2)) // For Odds
         ans[t++] = 2 * x - 1;
       for (int x: f(N / 2)) // For Evens
         ans[t++] = 2 * x;
     }
     memo.put(N, ans);
     return ans;
   }
 }
