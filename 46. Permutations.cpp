class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permute(0, res, nums);
        return res;
    }
    
    void permute(int pos, vector<vector<int>>& res, vector<int>& nums) {
        if (pos == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            swap(nums[i], nums[pos]);
            permute(pos + 1, res, nums);
            swap(nums[i], nums[pos]);
        }
    }
};
