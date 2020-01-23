/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int p1 = 0;
        int p2 = 1;
        int p3 = n - 1;

        int closest = 0;
        int currDiff = INT_MAX;
        while (p1 < n - 2) {
            int num1 = nums[p1];
            while (p2 < p3) {
                int sum = num1 + nums[p2] + nums[p3];
                int diff = abs(sum - target);
                if (diff < currDiff) {
                    closest = sum;
                    currDiff = diff;
                }

                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    p2++;
                } else {
                    p3--;
                }
            }
            p1++;
            p2 = p1 + 1;
            p3 = n - 1;
        }
        return closest;
    }
};
// @lc code=end
