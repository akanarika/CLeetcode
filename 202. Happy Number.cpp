/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        int prev = 0;
        int curr = n;
        unordered_set<int> visited;
        while (curr != prev) {
            visited.insert(curr);
            int sum = 0;
            prev = curr;
            int num = curr;
            curr = 0;
            while (num > 0) {
                curr += (num % 10) * (num % 10);
                num /= 10;
            }
            if (visited.find(curr) != visited.end()) return curr == 1;
        }
        return curr == 1;
    }
};
// @lc code=end
