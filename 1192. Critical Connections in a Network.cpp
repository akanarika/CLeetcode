/*
 * @lc app=leetcode id=1192 lang=cpp
 *
 * [1192] Critical Connections in a Network
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        if (n <= 1) return {};

        unordered_map<int, unordered_set<int>> conns;
        for (auto conn : connections) {
            int x = conn[0];
            int y = conn[1];
            conns[x].insert(y);
            conns[y].insert(x);
        }

        vector<int> level(n, 0);
        vector<vector<int>> res;
        level[0] = 1;
        dfs(0, 1, level, res, conns, 0);
        return res;
}

    int dfs(int i, int lvl, vector<int>& level, vector<vector<int>>& res, unordered_map<int, unordered_set<int>>& conns, int par) {
        if (i != 0) level[i] = lvl + 1;

        for (auto p : conns[i]) {
            if (p == par) continue;
            if (level[p] == 0) {
                level[i] = min(level[i], dfs(p, lvl + 1, level, res, conns, i));
            } else level[i] = min(level[i], level[p]);
        }

        if (level[i] == lvl + 1) res.push_back({i, par});

        return level[i];
    }
};
// @lc code=end
