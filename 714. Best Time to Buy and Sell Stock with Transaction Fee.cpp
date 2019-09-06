class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.empty()) return 0;

        int hold = -prices[0];
        int empty = 0;

        for (int i = 1; i < prices.size(); i++) {
            int e = max(empty, prices[i] + hold - fee);
            int h = max(empty - prices[i], hold);
            empty = e;
            hold = h;
        }
        
        return empty;
    }
};
