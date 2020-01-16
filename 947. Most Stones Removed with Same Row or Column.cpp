/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 */

// @lc code=start
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        if (stones.empty()) return 0;
        
        unordered_map<int, bool> visited;
        stack<vector<int>> s;
        int count = 0;
        int max_count = 0;
        
        for (int i = 0; i < stones.size(); i++) {
            if (visited[i]) continue;
            s.push(stones[i]);
            visited[i] = true;
            while (!s.empty()) {
                count++;
                auto idx = s.top();
                s.pop();
                for (int j = 0; j < stones.size(); j++) {
                    if (visited[j]) continue;
                    if (stones[j][0] == idx[0] || stones[j][1] == idx[1]) {
                        s.push(stones[j]);
                        visited[j] = true;
                    }
                }
                
            }
            max_count += count - 1;
            count = 0;
        }
        return max_count;
    }
};
// @lc code=end
