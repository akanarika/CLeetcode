class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (1 + n) * n / 2;
        for (const auto& num : nums) sum -= num;
        
        return sum;
    }
};

/**
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
**/
