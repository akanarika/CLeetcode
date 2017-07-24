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