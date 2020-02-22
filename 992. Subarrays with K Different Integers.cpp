/*
 * @lc app=leetcode id=992 lang=cpp
 *
 * [992] Subarrays with K Different Integers
 */

// @lc code=start
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        vector<int> cnt(A.size() + 1, 0);
        int curr = 0;
        int prev = 0;
        int j = 0;
        int res = 0;
        for (int i = 0; i < A.size(); i++) {
            if (cnt[A[i]]++ == 0) curr++;
            if (curr > K) {
                prev = 0;
                cnt[A[j++]]--;
                curr--;
            }
            while (cnt[A[j]] > 1) {
                cnt[A[j++]]--;
                prev++;
            }
            if (curr == K) res += prev + 1;
        }
        return res;
    }
};
// @lc code=end
