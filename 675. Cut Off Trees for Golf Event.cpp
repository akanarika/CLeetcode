/*
 * @lc app=leetcode id=675 lang=cpp
 *
 * [675] Cut Off Trees for Golf Event
 */

// @lc code=start
class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        if (forest.empty() || forest[0].empty()) return -1;

        h = forest.size();
        w = forest[0].size();
        vector<tuple<int, int, int>> hi;

        for (int r = 0; r < h; r++) {
            for (int c = 0; c < w; c++) {
                if (forest[r][c] > 1) {
                    hi.emplace_back(forest[r][c], r, c);
                }
            }
        }
        sort(hi.begin(), hi.end());

        int sum = 0;
        int y = 0;
        int x = 0;

        for (int i = 0; i < hi.size(); i++) {
            int r = get<1>(hi[i]);
            int c = get<2>(hi[i]);
            int step = bfs(y, x, r, c, forest);
            if (step == -1) return -1;
            sum += step;
            y = r;
            x = c;
        }
        return sum;
    }

private:
    int bfs(int r, int c, int nr, int nc, const vector<vector<int>>& forest) {
        static int off[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        vector<vector<int>> visited(h, vector<int>(w, 0));

        queue<pair<int, int>> idx;
        idx.emplace(r, c);

        int step = 0;
        while (!idx.empty()) {
            int cnt = idx.size();
            while (cnt--) {
                auto i = idx.front();
                idx.pop();
                const int y = i.first;
                const int x = i.second;
                if (y == nr && x == nc) return step;

                for (int i = 0; i < 4; i++) {
                    const int yy = y + off[i][0];
                    const int xx = x + off[i][1];
                    if (yy < 0 || yy == h || xx < 0 || xx == w || !forest[yy][xx] || visited[yy][xx]) continue;
                    idx.emplace(yy, xx); 
                    visited[yy][xx] = 1;
                }
            }
            step++;
        }
        return -1;
    }

    int w, h;

};
// @lc code=end
