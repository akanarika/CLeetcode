class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> l;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == '(') l.push(i);
            else if (c == ')') {
                int j = l.top();
                l.pop();
                reverse(s.begin() + j + 1, s.begin() + i);
            }
        }
        string res;
        for (char c : s) {
            if (c != '(' && c != ')') res += c;
        }
        return res;
    }
};
