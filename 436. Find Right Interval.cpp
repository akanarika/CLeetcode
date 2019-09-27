class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> m;
        int i = 0;
        for (auto& interval : intervals) {
            if (m.find(interval[0]) == m.end()) m[interval[0]] = i++;
        }

        vector<int> res;
        for (auto interval : intervals) {
            auto found = m.lower_bound(interval[1]);
            if (found != m.end()) res.push_back(found->second);
            else res.push_back(-1);
        }
        return res;
    }
};
