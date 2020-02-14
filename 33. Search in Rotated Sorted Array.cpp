/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int left = 0;
        int right = nums.size();
        return search(nums, left, right, target);
    }

private:
    int search(vector<int>& nums, int left, int right, int target) {
        if ((nums[left] < nums[right - 1]) && (target < nums[left] || target > nums[right - 1])) return -1;
        if (left == right || left == right - 1) return nums[left] == target ? left : -1;
        int mid = (left + right) / 2;
        int findLeft = -1;
        if ((nums[left] > nums[mid - 1]) || (nums[left] <= nums[mid - 1]) && (target >= nums[left] && target <= nums[mid - 1])) findLeft = search(nums, left, mid, target);
        int findRight = -1;
        if ((nums[mid] > nums[right - 1]) || (nums[mid] <= nums[right - 1]) && (target >= nums[mid] && target <= nums[right - 1])) findRight = search(nums, mid, right, target);
        if (findLeft == -1 && findRight == -1) return -1;
        return findLeft == -1 ? findRight : findLeft;
    }
};
// @lc code=end**

/* class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        while (s <= e) {
            int m = (s + e) / 2;
            if (nums[m] < target) {
                if (nums[e] > target) {
                    s = m + 1;
                } else if (nums[e] < target) {
                    if (nums[m] < nums[e]) e = m;
                    else s = m + 1;
                } else return e;
            } else if (nums[m] > target) {
                if (nums[s] < target) {
                    e = m;
                } else if (nums[s] > target) {
                    if (nums[s] > nums[m]) e = m;
                    else s = m + 1;
                } else return s;
            } else return m;
        }
        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        return search(nums, target, 0, nums.size());
    }

    int search(vector<int>& nums, int target, int s, int e) {
        int p = (s + e) / 2;
        if (nums[p] == target) return p;
        if (s == e || s == e - 1) {
            return -1;
        }
        if (nums[p] < target) {
            if (nums[s] <= nums[p]) {
                return search(nums, target, p, e);
            } else {
                if (nums[e - 1] < target) {
                    return search(nums, target, s, p);
                } else {
                    return search(nums, target, p, e);
                }
            }
        } else {
            if (nums[s] <= nums[p]) {
                if (nums[s] <= target) {
                    return search(nums, target, s, p);
                } else {
                    return search(nums, target, p, e);
                }
            } else {
                return search(nums, target, s, p);
            }
        }

    }
};
**/

