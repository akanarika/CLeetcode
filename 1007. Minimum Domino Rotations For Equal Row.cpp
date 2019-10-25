/*
 * @lc app=leetcode id=1007 lang=cpp
 *
 * [1007] Minimum Domino Rotations For Equal Row
 */

// @lc code=start
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int> countA(7, 0);
        vector<int> countB(7, 0);
        vector<int> same(7, 0);
        for (int i = 0; i < A.size(); i++) {
            countA[A[i]]++;
            countB[B[i]]++;
            if (A[i] == B[i]) same[A[i]]++;
        }

        int res = INT_MAX;
        for (int i = 1; i < 7; i++) {
            if (countA[i] + countB[i] - same[i] >= A.size()) {
                res = min(min(countA[i], countB[i]) - same[i], res);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
// @lc code=end
