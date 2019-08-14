class Solution {
public:
    bool isPowerOfFour(int num) {
        bitset<32> bs(num);
        if (bs.count() != 1) return false;
        num |= num >> 16;
        num |= num >> 8;
        num |= num >> 4;
        num |= num >> 2;
        return (num & 3) == 1;
    }
};
