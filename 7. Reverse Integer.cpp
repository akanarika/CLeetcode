class Solution {
public:
    int reverse(int x) {
        if (x == 0) return x;
        
        int res = 0;
        while (x != 0) {
            int b = x - 10 * (x / 10);
            res = res * 10 + b;
            x /= 10;
            if (x) {
                if (res > 0 && (res > INT_MAX / 10 || res * 10 > INT_MAX - b)) return 0;
                if (res < 0 && (res < INT_MIN / 10 || res * 10 < INT_MIN - b)) return 0;
            }
        }
        
        return res;
    }
};

/**
class Solution {
public:
    int reverse(int x) {
        long res = 0;
        long b = 10;
        while (x) {
            res = res * 10 + x % b;
            x /= b;
        }
        return (res < int(1<<31) || res > int(~(1<<31))) ? 0 : int(res);
    }
};
**/
