class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s, p, 0, 0);
    }

    bool isMatch(string s, string p, int si, int pi) {
        if (pi < p.size()) {
            char c = p[pi++];
            if (c == '.') {
                if ((pi < p.size()) && (p[pi] == '*')) {
                    pi++;
                    bool match = isMatch(s, p, si, pi);
                    while (!match && (si < s.size())) {
                        si++;
                        match = isMatch(s, p, si, pi);
                    }
                    if (!match) return false;
                    else return true;
                } else {
                    if (si < s.size()) {
                        si++;
                        return isMatch(s, p, si, pi);
                    } else {
                        return false;
                    }
                }
            } else if (c != '*') {
                if ((pi < p.size()) && (p[pi] == '*')) {
                    pi++;
                    bool match = isMatch(s, p, si, pi);
                    while ((!match) && (si < s.size()) && (s[si++] == c)) {
                        match = isMatch(s, p, si, pi);
                    }
                    if (!match) return false;
                    else return true;
                } else {
                    if ((si < s.size()) && (s[si++] == c)) {
                        return isMatch(s, p, si, pi);
                    } else {
                        return false;
                    }
                }
            } else {
                return isMatch(s, p, si, pi);
            }
        }
        return si == s.size();
    }
};
