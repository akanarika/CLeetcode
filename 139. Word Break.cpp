/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return true;

        unordered_set<string> dict;
        int maxLen = 0;
        for (auto word : wordDict) {
            dict.insert(word);
            maxLen = max(maxLen, (int)word.length());
        }
        vector<bool> valid(s.length() + 1, false);
        valid[0] = true;
        for (int i = 0; i < s.length(); i++) {
            if (!valid[i]) continue;
            int len = 1;
            while (len <= maxLen) {
                if (len + i <= s.length() && !valid[len + i]) {
                    string sub = s.substr(i, len);
                    if (dict.count(sub)) {
                        valid[len + i] = true;
                    }
                }
                len++;
            }
        }
        return valid[s.length()];
    }
};
// @lc code=end

/**
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
**/
