/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        if (s.empty()) return true;

        vector<int> cmap(128, -1);
        vector<int> mapped(128, 0);
        for (int i = 0; i < s.length(); i++) {
            int sc = s[i];
            int tc = t[i]; 
            if ((cmap[sc] != -1 && cmap[sc] != tc) || (cmap[sc] == -1 && mapped[tc])) return false;
            cmap[sc] = tc;
            mapped[tc] = 1;
        }
        return true;
    }
};
// @lc code=end
