/*
 * @lc app=leetcode id=1057 lang=cpp
 *
 * [1057] Campus Bikes
 */

// @lc code=start
class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<vector<pair<int, int>>> dists(2000);
        for (int i = 0; i < workers.size(); i++) {
            for (int j = 0; j < bikes.size(); j++) {
                int dist = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                dists[dist].push_back(make_pair(i, j));
            }
        }
        
        vector<int> res(workers.size(), -1);
        vector<int> used(bikes.size(), 0);
        for (int d = 0; d < 2000; d++) {
            for (int k = 0; k < dists[d].size(); k++) {
                if (res[dists[d][k].first] == -1 && !used[dists[d][k].second]) {
                    res[dists[d][k].first] = dists[d][k].second;
                    used[dists[d][k].second] = 1;
                }
            }
        }
        return res;
    }
};
// @lc code=end
