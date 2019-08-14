class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = x ^ y;
        int res = 0;
        while (diff) {
            res += diff & 1;
            diff >>= 1;
        }
        return res;
    }
};
