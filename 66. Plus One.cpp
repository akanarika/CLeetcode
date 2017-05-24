class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int p = digits.size() - 1;
        int carry = 1;
        while (p >= 0) {
            int num = digits[p] + carry;
            digits[p] = num % 10;
            carry = num / 10;
            p--;
        }
        if (carry == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};