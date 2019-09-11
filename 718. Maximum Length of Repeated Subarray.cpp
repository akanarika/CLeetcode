class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<int> tmp(B.size(), 0);
        vector<vector<int>> dp(A.size(), tmp);
        int m = 0;
        for (int i = A.size() - 1; i >= 0; i--) {
            for (int j = B.size() - 1; j >= 0; j--) {
                if (A[i] == B[j]) {
                    if (i == A.size() - 1 || j == B.size() - 1) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i + 1][j + 1] + 1;
                    }
                    m = max(m, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return m;
    }
};
