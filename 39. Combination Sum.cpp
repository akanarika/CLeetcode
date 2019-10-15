/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        combineSum(res, {}, candidates, target, 0);
        return res;
    }

    void combineSum(vector<vector<int>>& res, vector<int> idx, vector<int> candidates, int target, int s) {
        if (target < 0) return;
        if (target == 0) res.push_back(idx);
        else {
            for (int i = s; i < candidates.size(); i++) {
                idx.push_back(candidates[i]);
                combineSum(res, idx, candidates, target - candidates[i], i);
                idx.erase(idx.begin() + idx.size() - 1);
            }
        }
    }
};
// @lc code=end

/**
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
**/

