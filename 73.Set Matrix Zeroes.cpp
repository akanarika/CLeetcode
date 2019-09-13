class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        if (matrix[0].empty()) return;

        int m = matrix.size();
        int n = matrix[0].size();
        int c = 1;
        int r = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0 && matrix[i][j] == 0) {
                    c = 0;
                }
                if (i == 0 && matrix[i][j] == 0) {
                    r = 0;
                }
                if ((i > 0 && j > 0) && matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) 
                for (int j = 0; j < n; j++)
                    matrix[i][j] = 0;
        }

        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0)
                for (int i = 1; i < m; i++)
                    matrix[i][j] = 0;
        }

        if (c == 0) {
            for (auto& row : matrix) row[0] = 0;
        }
        if (r == 0) {
            for (auto& num : matrix[0]) num = 0;
        }
    }
};
