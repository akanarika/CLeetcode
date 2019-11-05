/*
 * @lc app=leetcode id=679 lang=cpp
 *
 * [679] 24 Game
 */

// @lc code=start
class Solution {
private:
    bool isValid(vector<int>& nums) {
        double a = nums[0], b = nums[1], c = nums[2], d = nums[3];
        if (isValid(a + b, c, d) || isValid(a - b, c, d) || isValid(a * b, c, d) || b && isValid(a / b, c, d) ||
            isValid(a, b + c, d) || isValid(a, b - c, d) || isValid(a, b * c, d) || c && isValid(a, b / c, d) ||
            isValid(a, b, c + d) || isValid(a, b, c - d) || isValid(a, b, c * d) || d && isValid(a, b, c / d))
            return true;
        return false;
    }
    bool isValid(double a, double b, double c) {
        if (isValid(a + b, c) || isValid(a - b, c) || isValid(a * b, c) || b && isValid(a / b, c) ||
            isValid(a, b + c) || isValid(a, b - c) || isValid(a, b * c) || c && isValid(a, b / c))
            return true;
        return false;
    }
    bool isValid(double a, double b) {
        if ((abs(a + b - 24.0) < 0.001) ||
            (abs(a - b - 24.0) < 0.001) ||
            (abs(a * b - 24.0) < 0.001) ||
            (b && (abs(a / b - 24.0) < 0.001)))
            return true;
        return false;
    }
public:
    bool judgePoint24(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        do {
            if (isValid(nums)) return true;
        } while(next_permutation(nums.begin(), nums.end()));
        return false;
    }
};
// @lc code=end
