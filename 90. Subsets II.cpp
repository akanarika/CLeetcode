class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        backtrack(res, tmp, 0, nums);
        return res;
    }
private:
    void backtrack(vector<vector<int>>& res, vector<int>& tmp, int i, vector<int>& nums) {
        res.push_back(tmp);
        for (int ii = i; ii < nums.size(); ii++) {
            if (i != ii && nums[ii] == nums[ii - 1]) continue;
            tmp.push_back(nums[ii]);
            backtrack(res, tmp, ii + 1, nums);
            tmp.pop_back();
        }
    }
};
