class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for (int i = 0; i < nums.size(); i++) {
            q.push(nums[i]);
        }
        int res;
        while (k > 0) {
            res = q.top();
            q.pop();
            k--;
        }
        
        return res;
    }
};

/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
/**
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> kNums;
        for (const auto& num : nums) {
            if ((kNums.size() < k) || (num > kNums.top())) {
                kNums.push(num);
                while (kNums.size() > k) {
                    kNums.pop();
                }
            }
        }
        return kNums.top();
    }
};
**/
// @lc code=end
