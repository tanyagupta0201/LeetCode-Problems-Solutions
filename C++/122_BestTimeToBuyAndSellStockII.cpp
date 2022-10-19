//Name: Harshit Jain
//Date: 19/10/2022

/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share 
of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

*/

#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int maxProfit(vector<int>& prices) {
    //n: size of given array
    //s:sum of all the profit 
    int n=prices.size(),s=0;
    
    //run loop from 1 to n-1
    for(int i=1;i<n;i++){
        if(prices[i]>prices[i-1])
            s+=prices[i]-prices[i-1];  
    }
    
    return s;
}

int main()
{
    vector<int>prices = {7,1,5,3,6,4};
    
    //call function to get result
    int res = maxProfit(prices);
    
    cout << res;

    return 0;
}
