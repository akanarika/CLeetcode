class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int n = matrix.size();
        int m = matrix[0].size();
        int res = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    int size = 1;
                    while (checkBound(matrix, i, j, size, n, m) == 1) {
                        size++;
                    }
                    res = max(size, res);
                }
            }
        }
        
        return res * res;
    }
    
    int checkBound(vector<vector<char>>& matrix, int i, int j, int curr_size, int n, int m) {
        if (i + curr_size >= n || j + curr_size >= m) {
            return 0;
        }
        
        for (int ii = i; ii < i + curr_size && ii < n; ii++) {
            if (matrix[ii][j+curr_size] == '0') return 0;
        }
        for (int jj = j; jj < j + curr_size + 1 && jj < m; jj++) {
            if (matrix[i+curr_size][jj] == '0') return 0;
        }
        
        return 1;
    }
};