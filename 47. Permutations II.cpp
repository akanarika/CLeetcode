class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        generate(res, 0, nums);
        return res;
    }
private:
    void generate(vector<vector<int>>& res, int start, vector<int> nums) {
        if (start == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            if (i != start && nums[i] == nums[start]) continue;
            swap(nums[i], nums[start]);
            generate(res, start + 1, nums);
        }
    }
};
