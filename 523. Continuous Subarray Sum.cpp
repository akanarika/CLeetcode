class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;

        int sum = 0;
        for (auto num : nums) {
            sum += num;
        }

        if ((k != 0) && (sum % k == 0)) return true;
        else if ((k == 0) && (sum == 0)) return true;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (i > 0) sum -= nums[i - 1];
            if ((k != 0) && (sum % k == 0)) return true;
            else if ((k == 0) && (sum == 0)) return true;
            int ssum = sum;
            for (int j = nums.size() - 1; j > i + 1; j--) {
                ssum -= nums[j];
                if ((k != 0) && (ssum % k == 0)) return true;
                else if ((k == 0) && (ssum == 0)) return true;
            }
        }

        return false;
    }
};
