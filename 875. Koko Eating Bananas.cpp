/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int low = 0;
        int high = 1 + *max_element(piles.begin(), piles.end());
        while (low < high) {
            int m = (low + high) / 2;
            int count = 0;
            for (auto p : piles) {
                count += (p + m - 1) / m;
            }
            if (count > H) {
                low = m + 1;
            } else {
                high = m;
            }
        }
        return low;
    }
};
// @lc code=end
