/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        map<int, int> ng;

        int res = 1;
        for (int i = 0; i < nums.size(); i++) {
            ng[nums[i]] = 1;
            auto found = ng.lower_bound(nums[i]);
            while (found != ng.begin()) {
                found--;
                ng[nums[i]] = max(1 + found->second, ng[nums[i]]);
                res = max(res, ng[nums[i]]);
            }
        }

        return res;
    }
};
// @lc code=end
