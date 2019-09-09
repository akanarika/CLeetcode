class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> right(m, 1);
        vector<vector<int>> map(n, right);

        for (int p = 1; p < max(m, n); p++) {
            for (int i = p; (p < n) && (i < m); i++) {
                map[p][i] = map[p - 1][i] + map[p][i - 1];
            }

            for (int i = p; (p < m) && (i < n); i++) {
                map[i][p] = map[i - 1][p] + map[i][p - 1];
            }
        }

        return map[n - 1][m - 1];
    }
};
