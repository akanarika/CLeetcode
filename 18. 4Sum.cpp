/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int p1 = 0;
        int p4 = n - 1;
        vector<vector<int>> res;
        while (p1 < n - 3) {
            int num1 = nums[p1];
            while (p4 - p1 > 2) {
                int num4 = nums[p4];
                int p2 = p1 + 1;
                int p3 = p4 - 1;
                while (p2 < p3) {
                    int sum = num1 + num4 + nums[p2] + nums[p3];
                    if (sum == target) {
                        vector<int> v = {num1, nums[p2], nums[p3], num4};
                        if (res.empty() || v != *(res.rbegin())) res.push_back(v);
                        p3--;
                        while ((p2 < p3) && (nums[p3] == nums[p3 + 1])) p3--;
                    } else if (sum < target) {
                        p2++;
                        while ((p2 < p3) && (nums[p2] == nums[p2 - 1])) p2++;
                    } else {
                        p3--;
                        while ((p2 < p3) && (nums[p3] == nums[p3 + 1])) p3--;
                    }
                }
                p4--;
                while ((p4 - p1 > 2) && (nums[p4] == nums[p4 + 1])) p4--;
            }
            p1++;
            while ((p1 < n -3) && (nums[p1] == nums[p1 - 1])) p1++;
            p4 = n - 1;
        }
        return res;
    }
};
// @lc code=end
