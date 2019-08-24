class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty()) return -1;
        if (amount == 0) return 0;
        
        sort(coins.begin(), coins.end());
        unordered_map<int, int> fewest;
        int count = coinChange(coins, fewest, amount);
        if (count == INT_MAX) return -1;
        return count;
    }
    
    int coinChange(vector<int>& coins, unordered_map<int, int>& fewest, int amount) {
        if (amount < 0) return INT_MAX;
        if (fewest.find(amount) == fewest.end()) {
            int minCount = INT_MAX;
            for (const auto& coin : coins) {
                if (amount == coin) minCount = 1; 
                int currentCount = coinChange(coins, fewest, amount - coin);
                if (currentCount < INT_MAX) {
                    minCount = min(minCount, 1 + currentCount);
                }
            } 
            fewest[amount] = minCount;
            return minCount;
        }
        return fewest[amount];
    }
};