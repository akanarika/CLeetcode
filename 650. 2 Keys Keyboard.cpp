class Solution {
public:
    int minSteps(int n) {
        vector<int> opt(max(n + 1, 3), -1);
        opt[1] = 0;
        opt[2] = 2;
        
        return minSteps(n, opt);
    }

    int minSteps(int n, vector<int>& opt) {
        if (opt[n] != -1) return opt[n];

        int x = 2;
        int minStep = n;
        while (x <= n / 2) {
            if (n % x == 0) {
                minStep = min(minStep, minSteps(x, opt) + n / x);
            }
            x++;
        }
        opt[n] = minStep;

        return minStep;
    }
};
