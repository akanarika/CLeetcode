class Solution {
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

/**
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
