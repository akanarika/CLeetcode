class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int m = -1;
        int max = nums.size();
        int sum = max * (max + 1) / 2;
        for (auto num : nums) {
            sum -= num;
        }
        return sum;
    }
};
