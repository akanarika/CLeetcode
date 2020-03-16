/*
 * @lc app=leetcode id=628 lang=cpp
 *
 * [628] Maximum Product of Three Numbers
 */

// @lc code=start
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        return max(*nums.begin() * *(nums.begin() + 1) * *nums.rbegin(),
                *nums.rbegin() * *(nums.rbegin() + 1) * *(nums.rbegin() + 2));
        
    }
};
// @lc code=end
