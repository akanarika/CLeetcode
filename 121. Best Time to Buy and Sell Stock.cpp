class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int max_profit = 0;
        int min_price = prices[0];
        int p = 1;
        while (p < prices.size()) {
            if (prices[p] < min_price) {
                min_price = prices[p];
            } else {
                max_profit = max(prices[p] - min_price, max_profit);
            }
            p++;
        }
        return max_profit;
    }
};