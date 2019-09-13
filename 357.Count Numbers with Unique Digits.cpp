class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp = {1, 10};

        for (int i = 2; i <= min(n, 10); i++) {
            int x = 9;
            for (int j = 0; j < i - 1; j++) {
                x *= (9 - j);
            }
            dp.push_back(x + dp[i - 1]);
        }
       
        if (n >= 11) return dp[10];
        return dp[n];
    }
};
