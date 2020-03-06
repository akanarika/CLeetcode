/*
 * @lc app=leetcode id=726 lang=cpp
 *
 * [726] Number of Atoms
 */

// @lc code=start
class Solution {
public:
    string countOfAtoms(string formula) {
        istringstream in(formula);
        map<string, int> res;
        coa(in, res);
        string s = "";
        for (auto r : res) {
            s += r.first;
            if (r.second > 1) s += to_string(r.second);
        }
        return s;
    }
private:
    void coa(istringstream& in, map<string, int>& curr) {
        string s = "";
        while (in.peek() != EOF) {
            if (isdigit(in.peek())) {
                int num;
                in >> num;
                curr[s] += num;
                s.clear();
            } else if (isalpha(in.peek())) {
                char c;
                in >> c;
                if (isupper(c) && !s.empty()) {
                    curr[s] += 1;
                    s.clear();
                }
                s += c;
            } else if (in.peek() == ')') {
                if (!s.empty()) {
                    curr[s] += 1;
                    s.clear();
                }
                in.get();
                int num;
                in >> num;
                for (auto& p : curr) p.second *= num;
                return;
            } else if (in.peek() == '(') {
                if (!s.empty()) {
                    curr[s] += 1;
                    s.clear();
                }
                in.get();
                map<string, int> next;
                coa(in, next);
                for (auto n : next) curr[n.first] += n.second;
            }
        }
        if (!s.empty()) {
            curr[s] += 1;
        }
    }
};
// @lc code=end
