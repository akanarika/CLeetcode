class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        bool up = true;
        int i = 0;
        int j = 0;
        int h = matrix.size();
        int w = matrix[0].size();
        vector<int> res = {matrix[0][0]};
        while (i != h - 1 || j != w - 1) {
            if (up) {
                if (i - 1 >= 0 && j + 1 < w) {
                    i--;
                    j++;
                } else if (j + 1 < w) {
                    j++;
                    up = false;
                } else {
                    i++;
                    up = false;
                }
            } else {
                if (i + 1 < h && j - 1 >= 0) {
                    i++;
                    j--;
                } else if (i + 1 < h) {
                    i++;
                    up = true;
                } else {
                    j++;
                    up = true;
                }
            }
            res.push_back(matrix[i][j]);
        }
        return res;
    }
};
