// Name:-Ayushi Tiwari
// Date:- 05 October 2022

/* Problem 
122. Best Time to Buy and Sell Stock II
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

Constraints:
1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104

Approach:-
Case 1:- we can buy the stock.
   Option 1: To do no transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day,
   Option 2: The other option is to buy the stock on the current day. In this case, the net profit earned from the current transaction will be -prices[i]. As we are buying the stock, we are giving money out of our pocket, therefore the profit we earn is negative.
Case 2:- we can sell the stock. 
    Option 1: To do no transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day,
    Option 2: The other option is to sell the stock on the current day. In this case, the net profit earned from the current transaction will be +prices[i]. As we are selling the stock, we are putting the money into our pocket, therefore the profit we earn is positive.
As we are looking to maximize the profit earned, we will check the maximum value in both cases.*/

//SOLUTION
class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;

        int[][] dp = new int[n + 1][2];
        int[][] dp = new int[n + 1][2]; // First, we declare the dp array of size [n+1][2] as zero.
        for (int[] row: dp)
            Arrays.fill(row, -1);

        dp[n][0] = dp[n][1] = 0;
        // Next, we set the base condition, 
        dp[n][0] = dp[n][1] = 0; // we set dp[n][0] = dp[n][1] = 0(the case when we had exhausted the number of days of the stock market).

        int profit = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int val = 0; val < 2; val++) {
                if (val == 0)
                if (val == 0) //Case 1:- we can buy the stock
                    dp[i][val] = Math.max(-prices[i] + dp[i + 1][1], 0 + dp[i + 1][0]);

                else
                else // Cse 2:- We can sell the stock
                    dp[i][val] = Math.max(prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
            }
        }
        return dp[0][0];

        return dp[0][0]; //At last, we will print dp[0][0] as our answer.
    }
}
