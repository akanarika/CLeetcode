class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        for (auto num : nums) {
            if (lower < num) {
                res.push_back((lower + 1 == num) ? to_string(lower) : (to_string(lower) + "->" + to_string(num - 1)));
            }
            lower = (num == INT_MAX) ? INT_MAX : (num + 1);
        }
        if (nums.size() > 0) {
            int num = nums[nums.size() - 1];
            if (upper > num) {
                res.push_back((upper - 1 == num) ? to_string(upper) : (to_string(num + 1) + "->" + to_string(upper)));
            }
        } else {
            if (upper >= lower) res.push_back((upper - 1 == lower || upper == lower) ? to_string(upper) : (to_string(lower) + "->" + to_string(upper)));
        }

        return res; 
    }
};
