class Solution {
public:
    int maxProduct(vector<int>& nums) {
        unordered_map<int, pair<int, int>> m;
        if (nums[0] > 0) m[0] = make_pair(0, nums[0]);
        else m[0] = make_pair(nums[0], 0);
        
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int l = nums[i] * (m[i - 1].first);
            int r = nums[i] * (m[i - 1].second);
            if (nums[i] > 0) {
                m[i].first = min(nums[i], l);
                m[i].second = max(nums[i], r);
                res = max(res, m[i].second);
            } else {
                m[i].first = min(nums[i], r);
                m[i].second = max(nums[i], l);
                res = max(res, m[i].second);
            }
        }
        
        return res;
    }
};