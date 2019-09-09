class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;

        int w = obstacleGrid[0].size();
        int h = obstacleGrid.size();
        vector<long> row(w, 0);
        vector<vector<long>> o(h, row);
        if (obstacleGrid[0][0] == 1) return 0;
        o[0][0] = 1;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (i == 0 && j == 0) continue;
                if (obstacleGrid[i][j] == 1) {
                    o[i][j] = -1;
                    continue;
                }
                long up = (i > 0) ? o[i - 1][j] : 0;
                long left = (j > 0) ? o[i][j - 1] : 0;

                if (left == -1) left = 0;
                if (up == -1) up = 0;
                o[i][j] = left + up;
            }
        }

        if (o[h - 1][w - 1] == -1) return 0;
        return o[h - 1][w - 1];
    }
};
