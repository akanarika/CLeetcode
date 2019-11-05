/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

// @lc code=start
class Solution {
private:
    int findPath(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        int h = matrix.size();
        int w = matrix[0].size();
        if (dp[i][j] > 0) return dp[i][j];

        int num = matrix[i][j];
        int large = 1;
        if ((j - 1 >= 0) && (matrix[i][j - 1] > num)) {
            int left = findPath(matrix, dp, i, j - 1);
            large = max(large, left + 1);
        }
        if ((i - 1 >= 0) && (matrix[i - 1][j] > num)) {
            int up = findPath(matrix, dp, i - 1, j);
            large = max(large, up + 1);
        }
        if ((j + 1 < w) && (matrix[i][j + 1] > num)) {
            int right = findPath(matrix, dp, i, j + 1);
            large = max(large, right + 1);
        }
        if ((i + 1 < h) && (matrix[i + 1][j] > num)) {
            int down = findPath(matrix, dp, i + 1, j);
            large = max(large, down + 1);
        }
        dp[i][j] = large;
        return large;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int h = matrix.size();
        int w = matrix[0].size();
        vector<vector<int>> dp(h, vector<int>(w, 0));
        int res = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int path = findPath(matrix, dp, i, j);
                res = max(res, path);
            }
        }
        return res;
    }
};
// @lc code=end
