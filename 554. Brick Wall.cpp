class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> m;
        for (auto row : wall) {
            int sum = 0;
            for (int i = 0; i < row.size() - 1; i++) {
                sum += row[i];
                m[sum]++;
            }
        }
        int res = 0;
        for (auto p : m) {
            res = max(p.second, res);
        }
        return wall.size() - res;
    }
};
