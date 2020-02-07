/*
 * @lc app=leetcode id=801 lang=cpp
 *
 * [801] Minimum Swaps To Make Sequences Increasing
 */

// @lc code=start
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int N = A.size();
        vector<int> keep(N, N);
        vector<int> change(N, N);

        keep[0] = 0;
        change[0] = 1;
        for (int i = 1; i < N; i++) {
            if ((A[i] > A[i - 1]) && (B[i] > B[i - 1])) {
                keep[i] = keep[i - 1];
                change[i] = change[i - 1] + 1;
            }

            if ((A[i] > B[i - 1]) && (B[i] > A[i - 1])) {
                keep[i] = min(change[i - 1], keep[i]);
                change[i] = min(change[i], keep[i - 1] + 1);
            }
        }
        return min(keep[N - 1], change[N - 1]);
    }
};
// @lc code=end
