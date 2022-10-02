// Name: Adarsh Gupta
// Date: 02/10/2022
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int sell = 0;
        int n = prices.size();
        for(int i = 0; i<n; i++)
        {
            buy = min(buy, prices[i]);
            sell = max(sell, prices[i]-buy);
        }
        return sell;
    }
};
