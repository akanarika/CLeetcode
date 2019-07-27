class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') {
                ss.push(c);
            } else if (c == ')' || c == ']' || c == '}') {
                char pair = (c == ')') ? '(' : ((c == ']') ? '[' : '{');
                if (ss.empty() || ss.top() != pair) {
                    return false;
                }
                ss.pop();
            }
        }
        return ss.empty();
    }
};

/**
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int p = 0;
        while (p < s.size()) {
            if (s[p] == '(' || s[p] == '[' || s[p] == '{') {
                stk.push(s[p]);
            } else {
                switch (s[p]) {
                    case (')'):
                        if (!stk.empty() && stk.top() == '(') stk.pop();
                        else return false;
                        break;
                    case (']'):
                        if (!stk.empty() && stk.top() == '[') stk.pop();
                        else return false;
                        break;
                    case ('}'):
                        if (!stk.empty() && stk.top() == '{') stk.pop();
                        else return false;
                        break;
                }
            }
            p++;
        }
        return stk.empty();
    }
};
 
**/
