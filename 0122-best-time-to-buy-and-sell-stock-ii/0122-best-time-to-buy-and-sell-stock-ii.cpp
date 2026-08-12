class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minsofar = prices[0];
        
        for(int i = 0;i<prices.size();i++) {
            if(prices[i]<minsofar) {
                minsofar = prices[i];
            } else if(prices[i]>minsofar) {
                profit += prices[i] - minsofar;
                minsofar = prices[i];
            }
        }
        
        return profit;
    }
};