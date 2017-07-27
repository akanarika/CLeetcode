class Solution {
public:
    string longestPalindrome(string s) {
        if (s == "") return "";
        if (s.size() == 1) return s;
        string res = "";
        int len = 0;
        for (int i = 0; i < s.size(); i++) {
            expandString(s, i, i, res, len);
            expandString(s, i, i+1, res, len);
        }
        return res;
    }
private:
    void expandString(string s, int j, int k, string& res, int& len) {
        while (s[j] == s[k] && j >= 0 && k < s.size()) {
            if (k - j + 1 > len) {
                len = k - j + 1;
                res = s.substr(j, len);
            }
            if (j > 0 && k < s.size() - 1) {
                j--;
                k++;
            }
            else {
                break;
            }
        }
    }
};