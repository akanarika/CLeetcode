/*
 * @lc app=leetcode id=741 lang=cpp
 *
 * [741] Cherry Pickup
 */

// @lc code=start
class Solution {
private:
    vector<vector<vector<int>>> m;
    int dp(int x1, int x2, int y1, vector<vector<int>>& grid) {
        int y2 = x1 + y1 - x2;
        if (x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0) return -1;
        if (grid[x1][y1] < 0 || grid[x2][y2] < 0) {
            return m[x1][x2][y1] = -1;
        }
        if (m[x1][x2][y1] != INT_MIN) return m[x1][x2][y1];
        int res = max(max(dp(x1 - 1, x2 - 1, y1, grid),
                          dp(x1 - 1, x2, y1, grid)),
                      max(dp(x1, x2 - 1, y1 - 1, grid),
                          dp(x1, x2, y1 - 1, grid)));
        if (res < 0) return m[x1][x2][y1] = -1;
        int c1 = 0;
        int c2 = 0;
        if (grid[x1][y1] == 1) c1 = 1;
        if (x1 != x2 && grid[x2][y2] == 1) c2 = 1;
        return m[x1][x2][y1] = c1 + c2 + res;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int N = grid.size();
        m = vector<vector<vector<int>>>(N, vector<vector<int>>(N, vector<int>(N, INT_MIN)));
        m[0][0][0] = (grid[0][0] == 1);
        int res = dp(N - 1, N - 1, N - 1, grid);
        return res < 0 ? 0 : res;
    }
};
// @lc code=end
