class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {};
        for (int i = 0; i < nums.size(); i++) {
            int size = res.size();
            for (int j = 0; j < size; j++) {
                vector<int> newV = res[j];
                newV.push_back(nums[i]);
                res.push_back(newV);
            }
            res.push_back({nums[i]});
        }
        res.push_back({});
        return res;
    }
};
