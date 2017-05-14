class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            result ^= nums[i];
        }
        return result;
    }
};