class Solution {
public:
    int fib(int N) {
        vector<int> mem = {0, 1};
        for (int i = 2; i <= N; i++) {
            mem.push_back(mem[i - 1] + mem[i - 2]);
        }
        return mem[N];
    }
};
