/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) return {};
        deque<int> q;
        vector<int> res;
        int i = 0, j = 0;
        while (j - i < k) {
            while (!q.empty() && (q.back() < nums[j])) q.pop_back();
            q.push_back(nums[j++]);
        }
        res.push_back(q.front());
        while (j < nums.size()) {
            if (q.front() == nums[i++]) q.pop_front();
            while (!q.empty() && (q.back() < nums[j])) q.pop_back();
            q.push_back(nums[j++]);
            res.push_back(q.front());
        }
        return res;
    }
};
// @lc code=end
