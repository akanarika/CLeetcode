class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s, p, 0, 0);
    }
    
private:
    bool isMatch(string s, string p, int si, int pi) {
        int sn = s.length();
        int pn = p.length();
        
        while (pi < pn && si < sn) {
            if (pi == pn - 1 || p[pi + 1] != '*') { // next char is not '*'
                if ((p[pi] != '.' && s[si] == p[pi]) || p[pi] == '.') {
                    si++;
                    pi++;
                } else {
                    return false;
                }
            } else { // next char is '*'
                if (isMatch(s, p, si, pi + 2)) return true;
                int sii = si;
                while ((sii < sn) && (p[pi] == '.' || p[pi] == s[sii])) {
                    if (isMatch(s, p, sii + 1, pi + 2)) return true;
                    sii++;
                }
                return false;
            }
        }
        
        // is s has reached the end, p has not, but with '*'
        while (pi + 1 < pn && p[pi + 1] == '*') {
            pi += 2;
        }
        
        return pi == pn && si == sn;
    }
};

/**
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
**/
