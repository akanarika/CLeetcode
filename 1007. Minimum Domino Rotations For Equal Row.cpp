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

/**
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> sa(n, INT_MAX);
        vector<int> nsa(n, INT_MAX);
        vector<int> sb(n, INT_MAX);
        vector<int> nsb(n, INT_MAX);
        
        sa[0] = 1;
        nsa[0] = 0;
        sb[0] = 1;
        nsb[0] = 0;
        
        for (int i = 1; i < n; i++) {
            if (A[i] == A[i - 1]) {
                nsa[i] = nsa[i - 1];
                if (sb[i - 1] != INT_MAX) sb[i] = sb[i - 1] + 1;
            }
            if (B[i] == B[i - 1]) {
                nsb[i] = nsb[i - 1];
                if (sa[i - 1] != INT_MAX) sa[i] = sa[i - 1] + 1;
            }
            if (A[i] == B[i - 1]) {
                nsa[i] = min(nsa[i], sa[i - 1]);
                if (nsb[i - 1] != INT_MAX) sb[i] = min(sb[i], nsb[i - 1] + 1);
            }
            if (B[i] == A[i - 1]) {
                nsb[i] = min(nsb[i], sb[i - 1]);
                if (nsa[i - 1] != INT_MAX) sa[i] = min(sa[i], nsa[i - 1] + 1);
            }
            if (nsa[i - 1] == INT_MAX && sa[i - 1] == INT_MAX
               && nsb[i - 1] == INT_MAX && sb[i - 1] == INT_MAX) return -1;
        }
        
        return min(min(nsa[n - 1], sa[n - 1]), min(nsb[n - 1], sb[n - 1]));
    }
};
**/