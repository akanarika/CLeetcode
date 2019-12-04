/*
 * @lc app=leetcode id=753 lang=cpp
 *
 * [753] Cracking the Safe
 */

// @lc code=start
class Solution {
public:
    string crackSafe(int n, int k) {
        unordered_set<string> visited;
        string s = "";
        string res = "";
        int _n = n;
        while (_n > 0) {
            s += "0";
            _n--;
        }
        visited.insert(s);
        res = s;

        while (visited.size() < pow(k, n)) {
            string sub = s.substr(1, n - 1);
            for (int i = k - 1; i >= 0; i--) {
                s = sub + to_string(i);
                if (visited.find(s) == visited.end()) {
                    visited.insert(s);
                    res += to_string(i);
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end
