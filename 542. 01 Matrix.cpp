/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int h = matrix.size();
        int w = matrix[0].size();
        int len = h * w;
        vector<vector<int>> path(h, vector<int>(w, INT_MAX));
        queue<pair<int, int>> q;
        for (int r = 0; r < h; r++) {
            for (int c = 0; c < w; c++) {
                if (matrix[r][c] == 0) {
                    q.push(make_pair(r, c));
                    path[r][c] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto idx = q.front();
            q.pop();
            int r = idx.first;
            int c = idx.second;
            for (pair<int, int> idx : {make_pair(r - 1, c), make_pair(r + 1, c),
                    make_pair(r, c - 1), make_pair(r, c + 1)}) {
                int nr = idx.first;
                int nc = idx.second;
                if ((nr >= 0) && (nr < h) && (nc >= 0) && (nc < w) && (matrix[nr][nc] == 1)) {
                    if (path[nr][nc] > path[r][c] + 1) {
                        path[nr][nc] = path[r][c] + 1;
                        q.push(idx);
                    }
                }
            }
        }

        return path;
    }
};
// @lc code=end
