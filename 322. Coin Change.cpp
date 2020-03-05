/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
private:
    unordered_map<int, int> cnt;
    int change(vector<int>& coins, int amount) {
        if (cnt.count(amount)) return cnt[amount];
        int c = INT_MAX;
        for (auto coin : coins) {
            if (amount - coin >= 0) {
                int curr = change(coins, amount - coin);
                if (curr != INT_MAX && curr + 1 < c) {
                    c = curr + 1;
                }
            }
        }
        cnt[amount] = c;
        return c;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        sort(coins.begin(), coins.end());
        reverse(coins.begin(), coins.end());
        cnt[0] = 0;
        int c = change(coins, amount);
        return c == INT_MAX ? -1 : c;
    }
};
// @lc code=end

/**
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
**/

