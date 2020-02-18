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

/**
class Solution {
private:
    void permu(vector<int>& nums, vector<int> curr, vector<vector<int>>& res) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }
        for (int j = 0; j < nums.size(); j++) {
            if (find(curr.begin(), curr.end(), nums[j]) != curr.end()) continue;
            curr.push_back(nums[j]);
            permu(nums, curr, res);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permu(nums, {}, res);
        return res;
    }
};
**/
