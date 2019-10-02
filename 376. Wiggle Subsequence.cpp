class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int last = nums[1];
        int positive = (nums[1] - nums[0] > 0);
        if (nums[1] == nums[0]) positive = 2;
        int res = (nums[1] == nums[0] ? 1 : 2);
        for (int i = 2; i < nums.size(); i++) {
            if (positive == 1) {
                if (nums[i] - nums[i - 1] < 0) {
                    res++;
                    last = nums[i];
                    positive = 0;
                } else if (nums[i] - nums[i - 1] > 0) {
                    last = nums[i];
                }
            } else if (positive == 0) {
                if (nums[i] - nums[i - 1] < 0) {
                    last = nums[i];
                } else if (nums[i] - nums[i - 1] > 0) {
                    res++;
                    last = nums[i];
                    positive = 1;
                }
            } else if (positive == 2) {
                if (nums[i] - nums[i - 1] < 0) {
                    res++;
                    last = nums[i];
                    positive = 0;
                } else if (nums[i] - nums[i - 1] > 0) {
                    res++;
                    last = nums[i];
                    positive = 1;
                }
            }
        }
        return res;
    }
};
