class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int l = 0;
        int r = 0;
        for (const auto& c : s) {
            if (c == '(') {
                l++;
            } else if (c == ')') {
                if (l > 0) l--;
                else r++;
            }
        }
        vector<string> res;
        dfs(s, res, 0, l, r);
        return res;
    }
    
private:
    void dfs(string& s, vector<string>& res, int start, int l, int r) {
        if (l == 0 && r == 0 && isValid(s)) {
            res.push_back(s);
            return;
        }
        
        for (int i = start; i < s.length(); i++) {
            if (r > 0) {
                if (s[i] == ')' && (i == start || s[i] != s[i - 1])) {
                    string curr = s;
                    curr.erase(i, 1);
                    dfs(curr, res, i, l, r - 1);
                }
            } else if (l > 0) {
                if (s[i] == '(' && (i == start || s[i] != s[i - 1])) {
                    string curr = s;
                    curr.erase(i, 1);
                    dfs(curr, res, i, l - 1, r);
                }
            }
        }
    }
    
    bool isValid(string s) {
        int cnt = 0;
        for (const auto& c : s) {
            if (c == '(') cnt++;
            else if (c == ')') {
                if (cnt == 0) return false;
                else cnt--;
            }
        }
        return cnt == 0;
    }
};

/**
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
**/
