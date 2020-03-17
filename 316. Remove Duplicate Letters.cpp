/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26, 0);
        vector<int> seen(26, 0);
        for (const auto& c : s) {
            cnt[c - 'a']++;
        }

        string res;
        for (const auto& c : s) {
            cnt[c - 'a']--;
            if (res.empty()) {
                res += c;
                seen[c - 'a'] = 1;
                continue;
            }
            if (seen[c - 'a']) continue;

            while (!res.empty() && (c < res.back() && cnt[res.back() - 'a'] > 0)) {
                seen[res.back() - 'a'] = 0;
                res.pop_back();
            }
            res += c;
            seen[c - 'a'] = 1;
        }

        return res;
    }
};
// @lc code=end
