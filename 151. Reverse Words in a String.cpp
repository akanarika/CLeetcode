class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int start = 0;
        int i = 0;
        int j = 0;
        while (j < n) {
            if (s[j] != ' ') {
                if (start != 0) s[start++] = ' ';
                int i = start;
                while (s[j] != ' ' && j < n) {
                    s[start++] = s[j++];
                }
                reverse(s.begin() + i, s.begin() + start);
            }
            j++;
        }
        s.resize(start);
    }
};