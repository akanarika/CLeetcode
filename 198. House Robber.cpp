/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> robbed(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            robbed[i] = max(nums[i] + (i >= 2 ? robbed[i - 2] : 0),
                    i >= 1 ? robbed[i - 1] : 0);
        }
        return robbed[nums.size() - 1];
    }
};
// @lc code=end

/**
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }
};
**/
