/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
private:
    bool check(string s, int i, int j) {
        if (j == i) return true;
        while (j > i) {
            if (s[j] != s[i]) return false;
            j--;
            i++;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        if (s.empty()) return {};
        vector<vector<vector<string>>> pars(s.length());
        // begin: i
        for (int i = 0; i < s.length(); i++) {
            // end: j
            for (int j = i; j < s.length(); j++) {
                if (check(s, i, j)) {
                    if (i == 0) {
                        pars[j].push_back({s.substr(i, j - i + 1)});
                        continue;
                    }
                    for (auto p : pars[i - 1]) {
                        auto np = p;
                        np.push_back(s.substr(i, j - i + 1));
                        pars[j].push_back(np);
                    }
                }
            }
        }
        return pars[s.length() - 1];
    }
};
// @lc code=end
