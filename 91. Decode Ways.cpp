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
