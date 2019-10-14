/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> list;
        sub(res, list, nums, 0);
        return res;
    }

    void sub(vector<vector<int>>& res, vector<int> list, vector<int>& nums, int s) {
        res.push_back(list);
        for (int i = s; i < nums.size(); i++) {
            list.push_back(nums[i]);
            sub(res, list, nums, i + 1);
            list.erase(list.begin() + list.size() - 1);
        }
    }
};
// @lc code=end

/**
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
**/ 
