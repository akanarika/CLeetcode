/*
 * @lc app=leetcode id=247 lang=cpp
 *
 * [247] Strobogrammatic Number II
 */

// @lc code=start
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        map<char, char> m = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        vector<string> res;
        stack<string> s;
        if (n % 2) {
            s.push("1");
            s.push("8");
            s.push("0");
        } else {
            s.push("");
        }

        while (!s.empty()) {
            if (s.top().length() / 2 == n / 2) {
                while (!s.empty()) {
                    res.push_back(s.top());
                    s.pop();
                }
                return res;
            }
            stack<string> ns;
            while (!s.empty()) {
                string curr = s.top();
                s.pop();
                for (auto pair : m) {
                    if (((curr.length() + 2) / 2 == n / 2) && (pair.first == '0')) continue;
                    ns.push(pair.first + curr + pair.second);
                }
            }
            swap(s, ns);
        }
        return {};
    }
};
// @lc code=end
