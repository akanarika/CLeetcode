/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 */

// @lc code=start
class Solution {
private:
    double check(int row, int col, int N, int k, vector<vector<vector<double>>>& prob) {
        if (k == 0) return 1.0;
        if (prob[row][col][k] > -0.5) return prob[row][col][k];

        vector<vector<int>> idx = {{row - 1, col - 2}, {row - 1, col + 2},
                           {row + 1, col - 2}, {row + 1, col + 2},
                           {row - 2, col - 1}, {row - 2, col + 1},
                           {row + 2, col - 1}, {row + 2, col + 1}};
        double cprob = 0.0;
        for (auto i : idx) {
            int rr = i[0];
            int cc = i[1];
            if (rr < 0 || rr >= N || cc < 0 || cc >= N) continue;
            cprob += check(rr, cc, N, k - 1, prob) * 1.0 / 8.0;
        }
        prob[row][col][k] = cprob;
        return cprob;
    }

public:
    double knightProbability(int N, int K, int r, int c) {
        if (!N || !K) return 1.0;
        vector<vector<vector<double>>> prob(N, vector<vector<double>>(N, vector<double>(K + 1, -1.0)));
        return check(r, c, N, K, prob);
    }
};
// @lc code=end
