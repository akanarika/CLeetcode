class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxSub = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = max(nums[i], i > 0 ? nums[i] + nums[i - 1] : nums[i]);
            maxSub = max(maxSub, nums[i]);
        }
        return maxSub;
    }
};
