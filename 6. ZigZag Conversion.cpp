class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        string result = "";
        for (size_t i = 0; i < numRows; i++) {
            size_t j = i;
            while (j < s.length()) {
                result += s[j];
                if (i != 0 && i != numRows - 1) {
                    if (j + numRows + numRows - i - i - 2 < s.length()) {
                        result += s[j+numRows+numRows-i-i-2];
                    }
                }
                j += numRows + numRows - 2;
            }
        }
        return result;
    }
};

/**
class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if (numRows <= 1 || n <= numRows) return s;

        int left = numRows + numRows - 2;
        int right = 0;
        string res = "";
        for (int r = 0; r < numRows; r++) {
            int i = r;
            while (i < n) {
                res += s[i];
                if (left > 0) {
                    i += left;
                    if (i < n) res += s[i];
                }
                if (right > 0) i += right;
                else i += left;
            }
            left -= 2;
            right += 2;
        }

        return res;
    }
};
**/
