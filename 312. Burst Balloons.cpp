/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.empty()) return 0;
        int N = nums.size();
        vector<vector<int>> coin(N, vector<int>(N, 0));
        for (int len = 0; len < N; len++) {
            for (int i = 0; i < N; i++) {
                if (i + len >= N) continue;
                int maxCoin = 0;
                int j = i + len;
                for (int m = i; m <= j; m++) {
                    int left, right;
                    if (m == i) left = 0;
                    else left = coin[i][m - 1];
                    if (m == j) right = 0;
                    else right = coin[m + 1][j];
                    int l = (i == 0 ? 1 : nums[i - 1]);
                    int r = (j == N - 1 ? 1 : nums[j + 1]);
                    coin[i][j] = max(coin[i][j], left + l * nums[m] * r + right);
                }
            }
        }
        return coin[0][N - 1];
    }
};
// @lc code=end
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
