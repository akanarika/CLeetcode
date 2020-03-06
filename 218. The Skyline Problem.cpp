/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

// @lc code=start
class Solution {
public:
    typedef pair<int, int> pi;
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int N = buildings.size();
        vector<pair<int, int>> events;
        multiset<int> hs;
        for (const auto& b : buildings) {
            events.push_back(make_pair(b[0], b[2]));
            events.push_back(make_pair(b[1], -b[2]));
        }
        sort(events.begin(), events.end(), [](const auto& e1, const auto& e2) {
                return e1.first < e2.first || e1.first == e2.first && e1.second > e2.second;
        });

        int h = 0;
        vector<vector<int>> res;
        for (auto e : events) {
            bool enter = (e.second > 0);
            int x = e.first;
            if (enter) {
                int h = hs.empty() ? 0 : *hs.rbegin();
                if (e.second > h) res.push_back({x, e.second});
                hs.insert(e.second);
            } else {
                hs.erase(hs.equal_range(-e.second).first);
                int h = hs.empty() ? 0 : *hs.rbegin();
                if (-e.second > h) res.push_back({x, h});
            }
        }


        return res;
    }
};
// @lc code=end
