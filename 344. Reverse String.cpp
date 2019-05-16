class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty()) return; 
        size_t i = 0;
        size_t j = s.size() - 1;
        while (i < j) {
            char tmp = s[j];
            s[j] = s[i];
            s[i] = tmp;
            i++;
            j--;
        }
    }
};

/*
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
*/
