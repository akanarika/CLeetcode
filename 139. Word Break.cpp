class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return true;
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        
        vector<bool> dp(1 + s.length(), false);
        dp[0] = 1;
        
        for (int i = 1; i <= s.length(); i++) {
            if (dp[i]) continue;
            for (int prev = i - 1; prev >= 0; prev--) {
                if (dp[prev] && set.count(s.substr(prev, i - prev))) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        
        return dp[s.length()];
    }
};
