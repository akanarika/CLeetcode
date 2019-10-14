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
