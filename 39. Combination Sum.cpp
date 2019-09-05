class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.empty()) return {};

        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        vector<pair<int, vector<int>>> curr(1, make_pair(0, tmp));

        while (!curr.empty()) {
            vector<pair<int, vector<int>>> v;
            for (auto c : curr) {
                for (auto e : candidates) {
                    auto ci = c.first;
                    auto cv = c.second;
                    if ((!cv.empty()) && (e > cv[cv.size() - 1])) continue;

                    if (e + ci < target) {
                        vector<int> n(cv);
                        n.push_back(e);
                        v.push_back(make_pair(e + ci, n));
                    } else if (e + ci == target) {
                        vector<int> n(cv);
                        n.push_back(e);
                        res.push_back(n);
                    } else {
                        break;
                    }
                }
            }
            curr.clear();
            swap(v, curr);
        }

        return res;
    }
};
