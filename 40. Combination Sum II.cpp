/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        for (int i = 1; i <= n; i++) {
            combination(0, 0, i, target, {}, res, candidates);
        }

        return res;
    }

    void combination(int s, int d, int n, int target, vector<int> curr, vector<vector<int>>& res, vector<int>& candidates) {
        if (d == n) {
            if (target == 0) res.push_back(curr);
            return;
        }

        for (int i = s; i < candidates.size(); i++) {
            if (candidates[i] > target) break;
            if ((i > s) && (candidates[i] == candidates[i - 1])) continue;
            curr.push_back(candidates[i]);
            combination(i + 1, d + 1, n, target - candidates[i], curr, res, candidates);
            curr.pop_back();
        }
    }
};
// @lc code=end
