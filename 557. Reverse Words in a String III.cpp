class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) return s;
        size_t p1 = 0;
        for (size_t p2 = 0; p2 <= s.length(); p2++) {
            if (p2 == s.length() || s[p2] == ' ') {
                size_t p3 = p2 - 1;
                while (p1 < p3) {
                    char c = s[p3];
                    s[p3] = s[p1];
                    s[p1] = c;
                    p1++;
                    p3--;
                }
                p1 = p2 + 1;
            }
        }
        return s;
    }
};
