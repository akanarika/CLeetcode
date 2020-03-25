class Solution {
public:
    string longestPrefix(string s) {
        vector<int> v(s.length(), 0);
        int i = 0;
        int j = 1;
        while (j < s.length()) {
            if (s[i] == s[j]) {
                v[j++] = ++i;
            } else {
                while (i > 0 && s[i] != s[j]) {
                    i = v[i - 1];
                }
                if (s[i] == s[j]) {
                    v[j++] = ++i;
                } else {
                    v[j++] = i;
                }
            }
        }
        
        return s.substr(0, v[s.length() - 1]);
    }
};
