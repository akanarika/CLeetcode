class Solution {
public:
    int numTrees(int n) {
        if (n == 0) return 0;
        vector<int> opt;
        opt.push_back(1);
        opt.push_back(1);
        for (int i = 2; i <= n; i++) {
            int curr = 0;
            for (int j = 1; j <= i; j++) {
                curr += opt[i - j] * opt[j - 1];
            }
            opt.push_back(curr);
        }
        return opt[n];
    }
};