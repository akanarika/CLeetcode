class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        return num(d, f, target);
    }
    
private:
    unordered_map<int, unordered_map<int, int>> m;
    int num(int d, int f, int target) {
        if (target < d || target > d * f) {
            m[d][target] = 0;
            return 0;
        } else if (d == 1) {
            m[d][target] = 1;
            return 1;
        }
        if (m.find(d) != m.end() && m[d].find(target) != m[d].end()) return m[d][target];
        int res = 0;
        for (int of = 1; of <= f; of++) {
            res += num(d - 1, f, target - of);
            res %= 1000000007;
        }
        m[d][target] = res;
        return res;
    }
};