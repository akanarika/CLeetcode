class Solution {
public:
    string decodeString(string s) {
        if (s.length() < 2) return s;
        
        int p = 0;
        // a2[c]
        if (((s[0] >= 'a') && (s[0] <= 'z')) || ((s[0] >= 'A') && (s[0] <= 'Z'))) {
            while ((((s[p] >= 'a') && (s[p] <= 'z')) || ((s[p] >= 'A') && (s[p] <= 'Z'))) && (p < s.length())) {
                p++;
            }
            if (p == s.length()) return s;
            else return s.substr(0, p) + decodeString(s.substr(p));
        }
        
        // 3[a2[c]]
        int b1 = -1;
        int b2 = -1;
        int b = 0;
        while (p < s.length()) {
            if (s[p] == '[') {
                if (b == 0) b1 = p;
                b++;
            }
            if (s[p] == ']') {
                b--;
                if (b == 0) {
                    b2 = p;
                    break;
                }
            }
            p++;
        }
        if ((b2 == -1) && (p == s.length())) return s;
        
        int k = stoi(s.substr(0, b1));
        string ts = decodeString(s.substr(b1 + 1, b2 - (b1 + 1)));
        string fs;
        for (int i = 0; i < k; i++) {
            fs += ts;
        }
        
        if (b2 == s.length() - 1) return fs;
        return fs + decodeString(s.substr(b2 + 1));
    }
};