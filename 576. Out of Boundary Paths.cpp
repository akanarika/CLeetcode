class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if (N == 0) return 0;
        vector<int> Nv(N + 1, -1);
        vector<vector<int>> jNv(n, Nv);
        vector<vector<vector<int>>> ijNv(m, jNv);
        return findPath(ijNv, m, n, N, i, j);
    }
    
    int findPath(vector<vector<vector<int>>>& v, int m, int n, int N, int i, int j) {
        if (v[i][j][N] != -1) return v[i][j][N];
        int sum = 0;
        // m - row, n - col, i - row, j - col
        if (i == 0 || i == m - 1) {
            if (m == 1) sum++;
            sum++;
        }
        if (j == 0 || j == n - 1) {
            if (n == 1) sum++;
            sum++;
        }

        if (N == 1) {
            sum %= 1000000007;
            v[i][j][N] = sum;
            return sum;
        }

        int left, right, up, down;
        left = right = up = down = 0;
        if (j - 1 >= 0) left = findPath(v, m, n, N - 1, i, j - 1);
        if (j + 1 < n) right = findPath(v, m, n, N - 1, i, j + 1);
        if (i - 1 >= 0) up = findPath(v, m, n, N - 1, i - 1, j);
        if (i + 1 < m) down = findPath(v, m, n, N - 1, i + 1, j);
        sum += (left + right) % 1000000007 + (up + down) % 1000000007;
        sum %= 1000000007;
        v[i][j][N] = sum;
        return sum;
    }
};
