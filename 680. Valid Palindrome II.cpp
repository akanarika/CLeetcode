class Solution {
private:
    bool isValid(string s, bool canDelete, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return canDelete && (isValid(s, false, i + 1, j) || isValid(s, false, i, j - 1));
            }
            i++;
            j--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        return isValid(s, true, 0, s.length() - 1);
    }
};
