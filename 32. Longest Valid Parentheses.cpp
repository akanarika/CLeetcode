class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int res = 0;
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                if (!stk.empty() && s[stk.top()] == '(') {
                    stk.pop();
                    res = max(res, stk.empty() ? i + 1 : i - stk.top());
                } else {
                    stk.push(i);
                }
            }
        }
        return res;
    }
};

/**
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
**/
