class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        unordered_map<int, int> f;
        unordered_map<int, unordered_set<int>> s;
        int w = grid[0].size();
        int h = grid.size();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == 1) {
                    if ((i - 1 >= 0) && (grid[i - 1][j] == 1)) {
                        int k = f[50 * (i - 1) + j];
                        f[50 * i + j] = k;
                        s[k].insert(50 * i + j);
                        if ((j - 1 >= 0) && (grid[i][j - 1] == 1) && (f[50 * i + j - 1] != k)) {
                            int ok = f[50 * i + j - 1];
                            for (auto e : s[ok]) {
                                f[e] = k;
                                s[k].insert(e);
                            }
                            s.erase(ok);
                        }
                    } else if ((j - 1 >= 0) && (grid[i][j - 1] == 1)) {
                        int k = f[50 * i + j - 1];
                        f[50 * i + j] = k;
                        s[k].insert(50 * i + j);
                    } else {
                        f[50 * i + j] = 50 * i + j;
                        s[50 * i + j].insert(50 * i + j);
                    }
                }
            }
        }

        size_t count = 0;
        for (auto es : s) {
            count = max(count, es.second.size());
        }

        return count;
    }
};
