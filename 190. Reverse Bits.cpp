class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t b = 1 << 31;
        uint32_t mask = 1;
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            if ((n & mask) == mask) {
                res += b;
            }
            mask <<= 1;
            b >>= 1;
        }
        return res;
    }
};