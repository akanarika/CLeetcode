/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */

// @lc code=start
class Solution {
public:
    int numTilings(int N) {
        if (N == 1) return 1;
        /**
        0 - x
            x
        -----
        1 -  x
            x
        -----
        2 - x
             x
         **/

        vector<vector<int>> dp = vector<vector<int>>(N + 1, vector<int>(3, 0));
        dp[0][0] = 1;
        dp[1][0] = 1;
        dp[1][1] = 1;
        dp[1][2] = 1;
        for (int i = 2; i <= N; i++) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 2][0]) % 1000000007 + (dp[i - 2][1] + dp[i - 2][2]) % 1000000007;
            dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
            dp[i][2] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][0] %= 1000000007;
            dp[i][1] %= 1000000007;
            dp[i][2] %= 1000000007;
        }
        return dp[N][0];
    }
};
// @lc code=end
