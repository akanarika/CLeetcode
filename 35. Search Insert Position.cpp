/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        return search(nums, 0, n, target);
    }

private:
    int search(vector<int>& nums, int left, int right, int target) {
        int mid = (right + left) / 2;
        if (left == right) {
            if (nums[left] < target) return left + 1;
            return left;
        }
        if (target < nums[left]) return left;
        else if (target <= nums[mid]) {
            return search(nums, left, mid, target);
        } else if (target <= nums[right - 1]) {
            return search(nums, mid, right, target);
        } else return right;
    }
};
// @lc code=end
