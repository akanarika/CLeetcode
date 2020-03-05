/*
 * @lc app=leetcode id=1139 lang=cpp
 *
 * [1139] Largest 1-Bordered Square
 */

// @lc code=start
class Solution {
private:
    bool check(int r, int c, int w, vector<vector<int>>& grid) {
        for (int i = r; i < r + w; i++) if (!grid[i][c]) return false;
        for (int i = c; i < c + w; i++) if (!grid[r][i]) return false;
        for (int i = r; i < r + w; i++) if (!grid[i][c + w - 1]) return false;
        for (int i = c; i < c + w; i++) if (!grid[r + w - 1][i]) return false;
        return true;
    }
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int large = 0;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c]) {
                    for (int w = large + 1; w + c - 1 < grid[0].size() && w + r - 1 < grid.size(); w++) {
                        if (check(r, c, w, grid)) large = max(large, w);
                    }
                }
            }
        }
        return large * large;
    }
};
// @lc code=end
