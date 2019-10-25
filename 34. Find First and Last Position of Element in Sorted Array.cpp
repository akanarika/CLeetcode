/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        int left = search(nums, target, 0, nums.size() - 1, true);
        int right = search(nums, target, 0, nums.size() - 1, false);
        return {left, right};
    }
    int search(vector<int>& nums, int target, int s, int e, bool left) {
        if (s == e) {
            if (nums[s] == target) {
                return s;
            } else {
                return -1;
            }
        }
        int m = (s + e) / 2;
        if (nums[m] < target) {
            return search(nums, target, m + 1, e, left);
        } else if (nums[m] > target) {
            return search(nums, target, s, m, left);
        } else {
            if (left) return search(nums, target, s, m, true);
            else {
                if (m < nums.size() - 1 && nums[m + 1] != target) return m;
                return search(nums, target, m + 1, e, false);
            }
        }
    }
};
// @lc code=end
