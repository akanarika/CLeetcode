class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        int left = 0;
        int right = 0;
        for (const auto& c : s) {
            if (c == '(') {
                left++;
            } else if (c == ')') {
                if (left == 0) {
                    right++;
                } else {
                    left--;
                }
            }
        }
        remove(s, 0, 0, left, right, res);
        if (res.empty()) res.push_back(string());
        return res;
    }

    bool isValid(string s) {
        int left = 0;
        for (const auto& c : s) {
            if (c == '(') {
                left++;
            } else if (c == ')') {
                left--;
                if (left < 0) {
                    return false;
                }
            }
        }
        return left == 0;
    }

    void remove(string s, int lstart, int rstart, int l, int r, vector<string>& res) {
        if (isValid(s)) {
            res.push_back(s);
            return;
        }

        if (l > 0) {
            for (int i = lstart; i < s.length(); i++) {
                if ((s[i] == '(') && ((i == 0) || ((i > 0) && (s[i - 1] != '(')))) {
                    remove(s.substr(0, i) + s.substr(i + 1), i, rstart, l - 1, r, res);
                }
            }
        } else if (r > 0) {
            for (int i = rstart; i < s.length(); i++) {
                if ((s[i] == ')') && ((i == 0) || ((i > 0) && (s[i - 1] != ')')))) {
                    remove(s.substr(0, i) + s.substr(i + 1), lstart, i, l, r - 1, res);
                }
            }
        }
    }
};
