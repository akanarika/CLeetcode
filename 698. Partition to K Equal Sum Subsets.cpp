/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */

// @lc code=start
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (auto num : nums) sum += num;
        if (sum % k) return false;
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        vector<int> filled(k, 0);
        if (fill(sum / k, k, 0, nums, filled)) return true;
        return false;
    }

private:
    bool fill(int ave, int k, int ni, vector<int> nums, vector<int>& filled) {
        if (ni == nums.size()) return true;
        int num = nums[ni];
        for (int i = 0; i < k; i++) {
            if (ave - filled[i] >= num) {
                filled[i] += num;
                if (fill(ave, k, ni + 1, nums, filled)) return true;
                filled[i] -= num;
            }
        }
        return false;
    }
};
// @lc code=end
