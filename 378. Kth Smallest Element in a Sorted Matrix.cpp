/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1] + 1;

        while (low < high) {
            int num = low + (high - low) / 2;
            int less = 0;
            for (const auto& row : matrix) {
                less += distance(row.begin(), upper_bound(row.begin(), row.end(), num));
            }

            if (less < k) {
                low = num + 1;
            } else {
                high = num;
            }

        }

        return low;
    }
};
// @lc code=end
