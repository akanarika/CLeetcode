class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int sl = s.length();
        int tl = t.length();

        if ((sl != tl) && (sl != tl + 1) && (sl != tl - 1)) return false;

        int si = 0;
        int ti = 0;
        while ((si < s.length()) || (ti < t.length())) {
            if ((si < s.length()) && (ti < t.length()) && (s[si] == t[ti])) {
                si++;
                ti++;
            } else {
                if (sl == tl + 1) {
                    return s.substr(si + 1) == t.substr(ti);
                } else if (sl == tl - 1) {
                    return s.substr(si) == t.substr(ti + 1);
                } else {
                    return s.substr(si + 1) == t.substr(ti + 1);
                }
            }
        }

        return false;
    }
};
