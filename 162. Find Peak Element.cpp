/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.empty()) return -1;
        int low = 0;
        int high = nums.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if ((mid == 0 || nums[mid] > nums[mid - 1]) &&
                    (mid == nums.size() - 1 || nums[mid + 1] < nums[mid])) {
                return mid;
            } else if (mid != nums.size() - 1 && nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return -1;
    }
};
// @lc code=end
