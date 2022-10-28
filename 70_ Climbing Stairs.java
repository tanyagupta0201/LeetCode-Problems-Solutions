// Name:-Vatsal Singh
// Date:-28-10-2022


// LeetCode Java Problem 70_Climbing Stairs
/*
 You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
 */

 // Solution

class Solution {
    public static int climbStairs(int n) {   //  A recursive function
     if(n<=0){
      return 0;
     }
     else if (n == 1) {
      return 1;
     }
     else{
      int[] steps = new int[n + 1];
      steps[0] = 1;
      steps[1] = 1;
      for (int i = 2; i <= n; i++) {
      steps[i] = steps[i - 2] + steps[i - 1];
      }
    return steps[n];
    }
    }
    //  Driver Program to test the above function
   public static void main(String[] args) 
   {
     int n=3;
     System.out.println(climbStairs(n));
    }
   }