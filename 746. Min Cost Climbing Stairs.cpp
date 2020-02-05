/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> allCost(n + 1, 0);
        allCost[0] = cost[0];
        allCost[1] = cost[1];
        for (int i = 2; i < n; i++) {
            allCost[i] = min(allCost[i - 1] + cost[i], allCost[i - 2] + cost[i]);
        }
        return min(allCost[n - 1], allCost[n - 2]);
    }
};
// @lc code=end
