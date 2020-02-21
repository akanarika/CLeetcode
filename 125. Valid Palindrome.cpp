class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            while (!isalnum(s[l])) {
                l++;
                if (l == s.length()) return true;
            }
            while (!isalnum(s[r])) {
                r--;
                if (r < 0) return true;
            }
            if (l >= r) return true;
            else {
                if (tolower(s[l]) == tolower(s[r])) {
                    l++;
                    r--;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};