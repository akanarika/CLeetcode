/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        dp[0][0] = grid[0][0];

        int w = grid[0].size();
        int h = grid.size();
        for (int i = 0; i < max(w, h); i++) {
            // row
            if (i < h) {
                for (int iw = i; iw < w; iw++) {
                    // down
                    if (i + 1 < h) dp[i + 1][iw] = min(dp[i + 1][iw], dp[i][iw] + grid[i + 1][iw]);
                    // right
                    if (iw + 1 < w) dp[i][iw + 1] = min(dp[i][iw + 1], dp[i][iw] + grid[i][iw + 1]);
                }
            }
            // col
            if (i < w) {
                for (int ih = i; ih < h; ih++) {
                    //down
                    if (ih + 1 < h) dp[ih + 1][i] = min(dp[ih + 1][i], dp[ih][i] + grid[ih + 1][i]);
                    // right
                    if (i + 1 < w) dp[ih][i + 1] = min(dp[ih][i + 1], dp[ih][i] + grid[ih][i + 1]);
                }
            }
        }

        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};
// @lc code=end
