class NumMatrix {
    vector<vector<int>> m;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            m = matrix;
            return;
        }
        int h = matrix.size();
        int w = matrix[0].size();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int left = (j == 0) ? 0 : matrix[i][j - 1];
                int up = (i == 0) ? 0 : matrix[i - 1][j];
                int upLeft = (i == 0 || j == 0) ? 0 : matrix[i - 1][j - 1];
                matrix[i][j] += left + up - upLeft;
            }
        }
        m = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (m.empty()) return 0;
        if (m[0].empty()) return 0;
        int left = (col1 == 0) ? 0 : m[row2][col1 - 1];
        int up = (row1 == 0) ? 0 : m[row1 - 1][col2];
        int upLeft = (col1 == 0 || row1 == 0) ? 0 : m[row1 - 1][col1 - 1];
        return m[row2][col2] - up - left + upLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
