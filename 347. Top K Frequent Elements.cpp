/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto num : nums) {
            m[num]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto p : m) {
            pq.push(make_pair(p.second, p.first));
        };

        vector<int> res;
        while (!pq.empty()) {
            if (pq.size() > m.size() - k) {
                res.push_back(pq.top().second);
            }
            pq.pop();
        }


        return res;
    }
};
// @lc code=end
