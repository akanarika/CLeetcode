class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        long dd = labs(dividend);
        long dr = labs(divisor);

        long res = 0;
        while (dd >= dr) {
            long curr = dr;
            int i = 0;
            while ((curr << 1) < dd) {
                curr <<= 1;
                i++;
            }
            dd = dd - curr;
            res += (1 << i);
        }
        return (dividend > 0) ^ (divisor > 0) ? -res : res;
    }
};
