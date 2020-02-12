/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

// @lc code=start
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_map<int, int> trusting;
        unordered_map<int, int> trusted;

        for (auto pair : trust) {
            int a = pair[0];
            int b = pair[1];
            trusting[a]++;
            trusted[b]++;
        }

        unordered_set<int> res;
        for (int i = 1; i <= N; i++) {
            if (!trusting.count(i)) {
                res.insert(i);
            }
        }

        int judge = -1;
        for (auto t : res) {
            if (trusted.count(t) && trusted[t] == N - 1 || !trusted.count(t) && N == 1) {
                if (judge != -1) return -1;
                judge = t;
            }
        }

        return judge;
    }
};
// @lc code=end
