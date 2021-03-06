class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int all = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) all += prices[i] - prices[i - 1];
        }
        
        return all;
    }
};
