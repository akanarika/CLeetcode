/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int kidi = g.size() - 1;
        int cooi = s.size() - 1;
        int sum = 0;
        while (kidi >=0 && cooi >= 0) {
            if (s[cooi] >= g[kidi]) {
                sum++;
                kidi--;
                cooi--;
            } else {
                kidi--;
            }
        }
        return sum;
    }
};
// @lc code=end

/**
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int p = 0;
        int q = 0;
        int count = 0;
        while ((p < g.size()) && (q < s.size())) {
            if (g[p] <= s[q]) {
                count++;
                p++;
            }
            q++;
        }
        return count;
    }
};
**/

