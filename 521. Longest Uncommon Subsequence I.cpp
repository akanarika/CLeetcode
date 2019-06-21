class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a.length() != b.length() || a != b) {
            return max(a.length(), b.length());
        } else {
            return -1;
        }
    }
};

/**

class Solution {
public:
    int findLUSlength(string a, string b) {
        int len = 0;
        for (int i = 0; i < a.length(); i++) {
            for (int j = a.length() - i; j > len; j--) {
                if (b.find(a.substr(i, j)) == string::npos) {
                    len = max(len, j);
                    break;
                } 
            }
        }
        
        for (int i = 0; i < b.length(); i++) {
            for (int j = b.length() - i; j > len; j--) {
                if (a.find(b.substr(i, j)) == string::npos) {
                    len = max(len, j);
                    break;
                } 
            }
        }
        
        return (len == 0)? -1 : len;
    }
};
**/