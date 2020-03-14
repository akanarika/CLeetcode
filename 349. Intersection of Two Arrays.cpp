/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> res;

        for (auto num : nums2) {
            if (s.count(num)) {
                s.erase(num);
                res.push_back(num);
            }
        }
        return res;
    }
};
// @lc code=end
