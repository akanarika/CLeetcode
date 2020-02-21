/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int w = matrix[0].size();
        int h = matrix.size();
        int low = 0;
        int high = w * h;
        if (target < matrix[0][0] || target > matrix[h - 1][w - 1]) return false;

        while (low < high) {
            int mid = low + (high - low) / 2;
            int r = mid / w;
            int c = mid % w;
            if (target == matrix[r][c]) return true;
            else if (target < matrix[r][c]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return false;
    }
};
// @lc code=end
