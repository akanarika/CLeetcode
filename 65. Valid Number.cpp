class Solution {
private:
    bool isint(string s) {
        if (s.empty()) return false;
        for (const auto& c : s) {
            if (!(c >= '0' && c <= '9')) return false;
        }
        return true;
    }
    
    bool issint(string s) {
        if (s.empty()) return false;
        if (s[0] != '+' && s[0] != '-') return false;
        return isint(s.substr(1));
    }
    
    bool isdec(string s) {
        if (s.empty()) return false;
        int d = s.find('.');
        string left = s.substr(0, d);
        string right = s.substr(d + 1);
        return ((issint(left) || isint(left) || left.empty() || left == "+" || left == "-") && isint(right))
            || ((issint(left) || isint(left)) && (isint(right) || right.empty()));
    }
    
    bool isexp(string s) {
        if (s.empty()) return false;
        int e = s.find('e');
        string left = s.substr(0, e);
        string right = s.substr(e + 1);
        return (issint(left) || isint(left) || isdec(left)) && (issint(right) || isint(right));
    }
    
public:
    bool isNumber(string s) {
        if (s.empty()) return false;
        int i = 0;
        int j = s.length() - 1;
        while (s[i] == ' ' && i < s.length()) i++;
        if (i == s.length()) return false;
        while (s[j] == ' ' && j >= 0) j--;
        if (j < 0) return false;
        s = s.substr(i, j - i + 1);
        return isint(s) || isdec(s) || isexp(s);
    }
};
