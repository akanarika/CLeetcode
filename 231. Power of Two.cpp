class Solution {
public:
    bool isPowerOfTwo(int n) {
        bitset<32> bs(n);
        return (n > 0) && (bs.count() == 1);
    }
};
