class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string rs = s;
        reverse(s.begin(), s.end());
        if (s == rs) return true;
        return false;
    }
};