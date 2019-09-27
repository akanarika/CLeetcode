class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        int p = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] < nums[i]) p = i + 1;
        }
        return search(nums, p, target, 0, nums.size());
    }

    bool search(vector<int>& nums, int p, int target, int s, int e) {
        if (s == e - 1) return nums[(p + s) % nums.size()] == target;

        int m = (s + e) / 2;
        if (nums[(p + m) % nums.size()] > target) return search(nums, p, target, s, m);
        else if (nums[(p + m) % nums.size()] < target) return search(nums, p, target, m, e);
        else return true;
    }
};
