class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int w = grid[0].size();
        int h = grid.size();
        set<set<int>> s;
        for (int j = 0; j < h; j++)
            for (int i = 0; i < w; i++)
                if (grid[j][i]) {
                    set<int> cs;
                    findIsland(cs, grid, i, j);
                    s.insert(cs);
                }
        
        set<set<int>> res;
        for (auto ss : s) {
            auto begin = *ss.begin();
            set<int> r;
            for (auto e : ss) {
                r.insert(e - begin);
            }
            res.insert(r);
        }
        return res.size();
    }

    bool findIsland(set<int>& cs, vector<vector<int>>& grid, int is, int js) {
        int w = grid[0].size();
        int h = grid.size();
        if ((is < 0) || (is >= w) || (js < 0) || (js >= h) || !grid[js][is]) return false;

        cs.insert(js * w * h + is);
        grid[js][is] = 0;
        bool right = findIsland(cs, grid, is + 1, js);
        bool down = findIsland(cs, grid, is, js + 1);
        bool left = findIsland(cs, grid, is - 1, js);
        bool up = findIsland(cs, grid, is, js - 1);
        return right || down || left || up;
    }
};
