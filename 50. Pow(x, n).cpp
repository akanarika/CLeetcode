class Solution {
public:
    double myPow(double x, int n) {
        if (n == 1) return x;
        if (n == -1) return 1.0 / x;
        if (n == 0) return 1;
        if (n < 0) {
            return n % 2 ? myPow(x * x, n / 2) / x : myPow(x * x, n / 2);
        }
        return n % 2 ? x * myPow(x * x, n / 2) : myPow(x * x, n / 2);
    }
};

/**
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        int pos = 1;
        unsigned int N = n > 0 ? n : -(long)(n);
        
        while (N > 0) {
            if (N % 2) {
                res *= x;
            }
            x *= x;
            N /= 2;
        }
        return n > 0 ? res : (1.0 / res);
    }
};
**/
