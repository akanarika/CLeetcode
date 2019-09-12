class Solution {
public:
    int maxA(int N) {
        vector<int> opt = {0,1,2,3,4,5};

        for (int i = 6; i <= N; i++) {
            opt.push_back(max(opt[i - 3] * 2, max(opt[i - 4] * 3, opt[i - 5] * 4)));
        }

        return opt[N];
    }
};
