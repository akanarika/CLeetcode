class Solution {
public:
    string addStrings(string num1, string num2) {
        string s;
        int p = num1.length() - 1;
        int q = num2.length() - 1;
        int carry = 0;
        while (p >= 0 || q >= 0 || carry) {
            int curr = (p >= 0 ? (num1[p--] - '0') : 0) + (q >= 0 ? (num2[q--] - '0') : 0) + carry;
            if (curr > 9) {
                carry = 1;
                curr -= 10;
            } else {
                carry = 0;
            }
            s = to_string(curr) + s;
        }
        return s;
    }
};
