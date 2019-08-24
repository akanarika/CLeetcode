class Solution {
public:
    vector<int> countBits(int num) {
        if (num == 0) return {0};
        
        vector<int> res = {0};
        for (int base = 1; base <= num; base *= 2) {
            int tmp = base;
            while ((tmp < base * 2) && (tmp <= num)) {
                res.push_back(1 + res[tmp - base]);
                tmp++;
            }
        }
        return res;
    }
};