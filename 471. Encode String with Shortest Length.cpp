class Solution {
private:
    vector<vector<string>> dp;
    string encodeRepeat(string& s, int i, int j) {
        string sub = s.substr(i, j - i + 1);
        int found = (sub + sub).find(sub, 1);
        if (found != string::npos && (found < sub.size())) {
            int count = sub.length() / found;
            string encoded = to_string(count) + "[" + dp[i][i + found - 1] + "]";
            if (encoded.length() < sub.length()) sub = encoded;
        }
        return sub;
    }
    
public:
    string encode(string s) {
        int n = s.length();
        dp = vector<vector<string>>(n, vector<string>(n));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                string sub = s.substr(i, len);
                dp[i][j] = encodeRepeat(s, i, j);
                for (int split = i; split < j; split++) {
                    string left = dp[i][split];
                    string right = dp[split + 1][j];
                    if (left.length() + right.length() < dp[i][j].length()) {
                        dp[i][j] = left + right;
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};
