class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty()) return "";

        stack<string> s;
        int i = 0;
        int j = 0;
        while (j <= path.length()) {
            if (j == path.length() || path[j] == '/') {
                if (j > i + 1) {
                    string sub = path.substr(i + 1, j - i - 1);
                    if (sub == "..") {
                        if (!s.empty()) s.pop();
                    } else if (sub != ".") {
                        s.push(sub);
                    }
                }
                i = j;
            }
            j++;
        }

        string str;
        while (!s.empty()) {
            str = "/" + s.top() + str;
            s.pop();
        }
        return str.empty() ? "/" : str;
    }
};
