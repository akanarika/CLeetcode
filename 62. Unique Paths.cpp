/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> path(m, vector<int>(n, 1));

        for (int r = 1; r < m; r++) {
            for (int c = 1; c < n; c++) {
                path[r][c] = path[r - 1][c] + path[r][c - 1];
            }
        }

        return path[m - 1][n - 1];
    }
};
// @lc code=end

/**
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> right(m, 1);
        vector<vector<int>> map(n, right);

        for (int p = 1; p < max(m, n); p++) {
            for (int i = p; (p < n) && (i < m); i++) {
                map[p][i] = map[p - 1][i] + map[p][i - 1];
            }

            for (int i = p; (p < m) && (i < n); i++) {
                map[i][p] = map[i - 1][p] + map[i][p - 1];
            }
        }

        return map[n - 1][m - 1];
    }
};
**/
