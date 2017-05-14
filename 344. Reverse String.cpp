class Solution {
public:
    string reverseString(string s) {
        string rs = "";
        for (size_t i = 0; i < s.length(); i++) {
            rs += s[s.length() - 1 - i];
        }
        return rs;
    }
};