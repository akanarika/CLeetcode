class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.empty()) return true;

        int count = 0;
        int leftMax = INT_MIN;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                if (count == 0) {
                    if (nums[i] < leftMax) nums[i] = nums[i - 1];
                    else nums[i - 1] = leftMax;
                    count++;
                }
                else return false;
            }
            leftMax = max(leftMax, nums[i - 1]);
        }

        return true;
    }
};
