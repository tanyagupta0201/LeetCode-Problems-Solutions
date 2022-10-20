// Name: Harshit Jain
// Date: 19/10/2022

/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share 
of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

*/

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
         // n: size of given vector
         // s:sum of all the profit 
        
        int n=prices.size(),s=0;
        
        for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1])
                s+=prices[i]-prices[i-1];  
        }
        return s;
    }
};
