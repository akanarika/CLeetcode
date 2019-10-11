/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        unordered_map<int, pair<int, int>> p;
        int largest = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    largest = max(largest, expand(matrix, i, j, p));
                }
            }
        }
        return largest;
    }

    int expand(vector<vector<char>>& matrix, int i, int j, unordered_map<int, pair<int, int>>& p) {
        if (p.find(i * matrix[0].size() + j) != p.end()) {
            auto pair = p[i * matrix[0].size() + j];
        }
        int large = 0;
        int lastW = matrix[0].size() - 1;
        for (int ii = i; ii < matrix.size(); ii++) {
            int largeW = j;
            if (matrix[ii][j] == '1') {
                for (int jj = j; jj <= lastW; jj++) {
                    if (matrix[ii][jj] == '1') largeW = jj;
                    else break;
                }
                lastW = min(lastW, largeW);
                large = max(large, (lastW - j + 1) * (ii - i + 1));
            } else break;
        }
        return large;
    }
};
// @lc code=end
