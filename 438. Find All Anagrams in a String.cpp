/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.empty() || p.empty()) return {};
        if (s.size() < p.size()) return {};
        vector<int> pv(26, 0);
        for (auto pc : p) {
            pv[pc - 'a']++;
        }
        int len = p.length();
        vector<int> sv(26, 0);
        for (int i = 0; i < len; i++) {
            sv[s[i] - 'a']++;
        }
        vector<int> res;
        if (sv == pv) res.push_back(0);
        for (int i = 1; i + len - 1 < s.length(); i++) {
            sv[s[i - 1] - 'a']--;
            sv[s[i + len - 1] - 'a']++;
            if (sv == pv) res.push_back(i);
        }
        return res;
    }
};
// @lc code=end
