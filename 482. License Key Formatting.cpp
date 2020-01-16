/*
 * @lc app=leetcode id=482 lang=cpp
 *
 * [482] License Key Formatting
 */

// @lc code=start
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int n = S.length();
        string res;
        for (auto it = S.rbegin(); it != S.rend(); it++) {
            if (*it == '-') {
                continue;
            }
            if (res.length() % (K + 1) == K) {
                res += '-';
            }
            res += toupper(*it);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
