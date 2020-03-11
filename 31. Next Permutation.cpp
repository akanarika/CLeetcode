/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty()) return;
        int n = nums.size() - 1;
        while (n-- > 0) {
            if (nums[n] >= nums[n + 1]) {
                continue;
            } else {
                int mini = n + 1;
                for (int i = n + 1; i < nums.size(); i++) {
                    if (nums[i] > nums[n] && nums[i] < nums[mini]) {
                        mini = i;
                    }
                }
                swap(nums[mini], nums[n]);
                sort(nums.begin() + n + 1, nums.end());
                return;
            }
        }
        sort(nums.begin(), nums.end());
    }
};
// @lc code=end
/**
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int lastSmaller = -1;
        int smallest = -1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                lastSmaller = i;
                smallest = i + 1;
            }
            if ((lastSmaller >= 0) && (i + 1 > lastSmaller) && (nums[i + 1] < nums[smallest]) && (nums[i + 1] > nums[lastSmaller])) {
                smallest = i + 1;
            }
        }
        if (lastSmaller >= 0) {
            swap(nums[lastSmaller], nums[smallest]);
            sort(nums.begin() + lastSmaller + 1, nums.end());
        } else {
            sort(nums.begin(), nums.end());
        }
    }
};

**/

