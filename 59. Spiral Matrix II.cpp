class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> row(n, 0);
        vector<vector<int>> matrix(n, row);

        int i = -1;
        int j = 0;
        int c = 1;
        int d = 0;
        while (c <= n * n) {
            int ii = i;
            int jj = j;
            if (d == 0) ii++;
            else if (d == 1) jj++;
            else if (d == 2) ii--;
            else if (d == 3) jj--;

            if (ii >= n || ii < 0 || jj >= n || jj < 0 ||
                    matrix[jj][ii] != 0) {
                d++;
                d %= 4;
            } else {
                i = ii;
                j = jj;
                matrix[j][i] = c++;
            }
        }

        return matrix;
    }
};
