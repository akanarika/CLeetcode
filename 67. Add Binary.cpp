class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int len_a = a.size();
        int len_b = b.size();
        int i = 0;
        string s = "";
        while (i < len_a || i < len_b) {
            int _a = i >= len_a ? 0 : a[i] - '0';
            int _b = i >= len_b ? 0 : b[i] - '0';
            if (_a + _b + carry > 2) {
                carry = 1;
                s = "1" + s;
            } else if (_a + _b + carry > 1) {
                carry = 1;
                s = "0" + s;
            } else if (_a + _b + carry > 0) {
                carry = 0;
                s = "1" + s;
            } else {
                s = "0" + s;
            }
            i++;
        }
        s = carry == 0 ? s : to_string(carry) + s;
        return s;
    }
};