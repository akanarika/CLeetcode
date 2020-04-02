class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int n = s.length();
        vector<int> dp(n, 0);
        dp[n - 1] = s[n - 1] != '0';
        for (int i = n - 2; i >= 0; i--) {
            int p = s[i] - '0';
            int q = s[i + 1] - '0';
            if (p == 1 || (p == 2 && q <= 6)) {
                dp[i] += i + 2 < n ? dp[i + 2] : 1;
            }
            if (p > 0) dp[i] += dp[i + 1];
        }
        return dp[0];
    }
};

/**
class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp;

        for(int i = 0; i < s.size(); i++) {
            int curr = 0;
            if (s[i] != '0') {
                if (i > 0) curr += dp[i - 1];
                else curr++;
            }
            if ((i > 0) && (s[i - 1] != '0') && (stoi(s.substr(i - 1, 2)) > 0) && (stoi(s.substr(i - 1, 2)) <= 26)) {
                if (i > 1) curr += dp[i - 2];
                else curr++;
            }
            if (curr == 0) return 0;
            dp.push_back(curr);
        }

        return dp[s.size() - 1];
        
    }
};
**/
