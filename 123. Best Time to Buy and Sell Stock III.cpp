class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        vector<int> left(prices.size(), 0);
        vector<int> right(prices.size(), 0);

        int lmin = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < prices[i - 1]) {
                lmin = min(prices[i], lmin);
                left[i] = left[i - 1];
            } else {
                left[i] = max(left[i - 1], prices[i] - lmin);
            }
        }

        int rmax = prices[prices.size() - 1];
        for (int i = prices.size() - 3; i >= 0; i--) {
            if (prices[i + 1] < prices[i + 2]) {
                right[i] = max(right[i + 1], rmax - prices[i + 1]);
            } else {
                rmax = max(prices[i + 1], rmax);
                right[i] = right[i + 1];
            }
        }
        
        int res = 0;
        for (int i = 0; i < prices.size(); i++) {
            res = max(res, left[i] + right[i]);
        }
        
        return res;
    }
};
