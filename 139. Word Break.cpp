class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> dict;
        for (auto word : wordDict) {
            dict[word] = true;
        }
        
        vector<int> dp(s.size(), 0);
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j >= 0; j--) {
                if (j == 0 || dp[j - 1]) {
                    string key = s.substr(j, i - j + 1);
                    if (dict[key]) {
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }
        return dp[s.size() - 1];
    }
};
