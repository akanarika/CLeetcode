/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int l = 0; l <= n; l++) {
            for (int i = 1; i + l <= n; i++) {
                int j = i + l;
                for (int k = i; k <= j; k++) {
                    int maxCoins = dp[i][k - 1] + nums[k] * nums[i - 1] * nums[j + 1] + dp[k + 1][j];
                    dp[i][j] = max(dp[i][j], maxCoins);
                }
            }
        }

        return dp[1][n];
    }
};
// @lc code=end
