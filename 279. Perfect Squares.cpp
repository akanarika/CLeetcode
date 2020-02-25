/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
private:
    vector<int> numSquare;
public:
    int numSquares(int n) {
        numSquare = vector<int>(n + 1, -1);
        int i = 0;
        while (i < 4 && i < n + 1) {
            numSquare[i] = i;
            i++;
        }

        return calc(n);
    }

    int calc(int n) {
        if (numSquare[n] != -1) return numSquare[n];

        int num = n / 2;
        int minCount = n;
        while (num >= 1) {
            if (num * num > n) {
                num--;
                continue;
            }
            int c = calc(n - num * num);
            if (c != -1) {
                minCount = min(minCount, 1 + c);
            }
            num--;
        }
        numSquare[n] = minCount;
        return minCount;
    }
};
// @lc code=end
