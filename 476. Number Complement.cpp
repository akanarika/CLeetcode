class Solution {
public:
    int findComplement(int num) {
        int complement = ~num;
        int bit = INT_MIN;
        while (bit & complement) {
            complement &= (~bit);
            bit >>= 1;
        }
        return complement;
    }
};
