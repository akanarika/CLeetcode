class Solution {
private:
    vector<long> subsum;
    vector<vector<int>> dp;
    int splitArray(vector<int>& nums, int n, int m) {
        if (m > n) return INT_MAX;
        if (dp[n][m] != INT_MAX) return dp[n][m];

        if (m == 1) {
            dp[n][m] = subsum[n - 1];
        } else {
            long minSum = INT_MAX;
            for (int i = m - 1; i < n; i++) {
                long splitSum = splitArray(nums, i, m - 1);
                long restSum = subsum[n - 1] - subsum[i - 1];
                minSum = min(minSum, max(splitSum, restSum));
            }
            dp[n][m] = minSum;
        }
        return dp[n][m];
    }

public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        subsum = vector<long>(n, 0);
        for (int i = 0; i < n; i++) {
            subsum[i] = (i > 0 ? subsum[i - 1] : 0) + nums[i];
        }
        dp = vector<vector<int>>(n + 1, vector<int>(m + 1, INT_MAX));
        return splitArray(nums, n, m);
    }
};
