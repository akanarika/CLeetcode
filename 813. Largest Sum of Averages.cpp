/*
 * @lc app=leetcode id=813 lang=cpp
 *
 * [813] Largest Sum of Averages
 */

// @lc code=start
class Solution {
private:
    vector<int> sums;
    vector<vector<double>> aves;
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int N = A.size();
        sums = vector<int>(N, 0);
        aves = vector<vector<double>>(N, vector<double>(K + 1, 0));

        for (int i = 0; i < N; i++) {
            sums[i] = A[i] + (i > 0 ? sums[i - 1] : 0);
            aves[i][1] = (double)sums[i] / (i + 1);
            for (int cnt = 2; cnt <= i + 1 && cnt <= K; cnt++) {
                double maxave = aves[i][1];
                for (int j = 0; j < i; j++) {
                    maxave = max(maxave, aves[j][cnt - 1] + (double)(sums[i] - sums[j]) / (double)(i - j));
                }
                aves[i][cnt] = maxave;
            }
        }
        return aves[N - 1][K];
    }
};
// @lc code=end
