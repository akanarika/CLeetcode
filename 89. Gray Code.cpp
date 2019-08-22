class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0) return {0};
        vector<int> base = {0, 1};
        int b = 1;
        for (int i = 1; i < n; i++) {
            b <<= 1;
            vector<int> newBase = base;
            for (int j = base.size() - 1; j >= 0; j--) {
                newBase.push_back(base[j] + b);
            }
            base = newBase;
        }
        return base;
    }
};
