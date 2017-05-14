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