class Solution {
public:
    int getSum(int a, int b) {
        bool carry = 0;
        int c = 0;
        int bit = 1;
        while (true) {
            if ((a & 1) && (b & 1)) {
                if (carry) c |= bit;
                carry = 1;
            } else if ((a & 1) || (b & 1)) {
                if (!carry) c |= bit;
                else carry = 1;
            } else {
                if (carry) c |= bit;
                carry = 0;
            }
            if (bit == 0x80000000) return c;
            bit <<= 1;
            a >>= 1;
            b >>= 1;
        }
    }
};
