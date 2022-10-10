class Solution {
    public int maxProfit(int[] prices) {
        int ans = 0;
        int minimumSofar = prices[0];
        for(int i =1; i < prices.length; i++){
            int currentprofit = prices[i]- minimumSofar;
            if(currentprofit>ans){
                ans=currentprofit;
            }
            minimumSofar = Math.min(minimumSofar, prices[i]);
            
        }
        return ans;
        
    }
}
