class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int h = grid.size();
        int w = grid[0].size();
        int peri = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j]) {
                    vector<vector<int>> offs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                    for (const auto& off : offs) {
                        int ii = i + off[0];
                        int jj = j + off[1];
                        if (ii < 0 || ii == h || jj < 0 || jj == w || !grid[ii][jj]) peri++;
                    }
                }
            }
        }
        return peri;
    }
};
