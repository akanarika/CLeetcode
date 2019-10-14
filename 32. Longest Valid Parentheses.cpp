/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                if (stk.empty()) stk.push(i);
                else {
                    if (s[stk.top()] == '(') stk.pop();
                    else stk.push(i);
                }
            }
        }

        int res = 0;
        if (stk.empty()) return s.length();
        else {
            int last = s.length();
            int curr = 0;
            while (!stk.empty()) {
                curr = stk.top();
                stk.pop();
                res = max(res, last - curr - 1);
                last = curr;
            }
            res = max(res, curr);
        }
        return res;
    }
};
// @lc code=end
