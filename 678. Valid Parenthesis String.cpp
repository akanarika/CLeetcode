class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left;
        stack<int> star;
        istringstream in(s);
        char c;
        int i = 0;
        while (in.peek() != EOF) {
            if (in >> c) {
                if (c == '(') {
                    left.push(i);
                } else if (c == '*') {
                    star.push(i);
                } else if (c == ')') {
                    if (!left.empty()) left.pop();
                    else if (!star.empty()) star.pop();
                    else return false;
                }
                i++;
            }
        }

        if (left.empty()) return true;
        int j = 0;
        while (!left.empty()) {
            i = left.top();
            left.pop();
            if (!star.empty()) {
                j = star.top();
                star.pop();
            } else {
                return false;
            }
            if (i > j) return false;
        }

        return true;
    }
};
