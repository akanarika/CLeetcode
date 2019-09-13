class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.empty()) return 0;

        long sum = 0;
        int dp0 = 0;
        int i = 0;
        for (auto a : A) {
            sum += a;
            dp0 += i * a;
            i++;
        }

        int m = dp0;
        vector<int> dp = {dp0};

        for (int i = 1; i < A.size(); i++) {
            dp.push_back(dp[i - 1] + sum - A[A.size() - i] * A.size());
            m = max(m, dp[i]);
        }

        return m;
    }
};
