/*
 * @lc app=leetcode id=561 lang=cpp
 *
 * [561] Array Partition I
 */

// @lc code=start
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = nums.size() - 1;
        int sum = 0;
        while (i-- > 0) {
            sum += nums[i--];
        }
        return sum;
    }
};
// @lc code=end
