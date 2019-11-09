/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int minNum = INT_MAX;
        for (auto& num : nums) {
            if (num <= minNum) {
                minNum = num;
                num = INT_MAX;
            }
        }
        int maxNum = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int num = nums[i];
            if ((num != INT_MAX) && (num < maxNum)) {
                return true;
            }
            if ((num != INT_MAX) && (num >= maxNum)) {
                maxNum = num;
            }
        }
        return false;
    }
};
// @lc code=end
