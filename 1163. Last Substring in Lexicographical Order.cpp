class Solution {
public:
    string lastSubstring(string s) {
        if (s.length() <= 1) return s;
        int i, j, k;
        i = 0;
        j = 1;
        k = 0;
        while (j + k < s.length()) {
            if (s[i + k] == s[j + k]) {
                k++;
            } else if (s[i + k] < s[j + k]) {
                i = j;
                j++;
                k = 0;
            } else {
                j++;
                k = 0;
            }
        }
        return s.substr(i);
    }
};