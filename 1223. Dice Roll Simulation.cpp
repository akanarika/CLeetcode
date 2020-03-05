/*
 * @lc app=leetcode id=1223 lang=cpp
 *
 * [1223] Dice Roll Simulation
 */

// @lc code=start
class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        constexpr int mod = 1e9 + 7;
        vector<vector<int>> cnt = vector<vector<int>>(7, vector<int>(16, 0));
        vector<vector<int>> ncnt = vector<vector<int>>(7, vector<int>(16, 0));
        for (int x = 1; x <= 6; x++) {
            cnt[x][1] = 1;
            cnt[x][0] = 5;
        }
        for (int i = 2; i <= n; i++) {
            ncnt = vector<vector<int>>(7, vector<int>(16, 0));
            for (int x = 1; x <= 6; x++) {
                for (int c = 1; c <= i && c <= rollMax[x - 1]; c++) {
                    ncnt[x][c] = cnt[x][c - 1];
                    ncnt[x][c] %= mod;
                    for (int y = 1; y <= 6; y++) {
                        if (x == y) continue;
                        ncnt[y][0] += ncnt[x][c];
                        ncnt[y][0] %= mod;
                    }
                }
            }
            swap(cnt, ncnt);
        }
        int res = 0;
        for (int x = 1; x <= 6; x++) {
            for (int c = 1; c <= n && c <= rollMax[x - 1]; c++) {
                res += cnt[x][c];
                res %= mod;
            }
        }
        return res;
    }
};
// @lc code=end
