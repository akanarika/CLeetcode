/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty() || word2.empty()) return max(word1.length(), word2.length());
        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), 0));

        for (int i = 0; i < word1.length(); i++) {
            for (int j = 0; j < word2.length(); j++) {
                int ins = i > 0 ? dp[i - 1][j] : j;
                int del = j > 0 ? dp[i][j - 1] : i;
                int rep = ((i > 0) && (j > 0)) ? dp[i - 1][j - 1] : max(i, j);
                dp[i][j] = min(min(ins, del) + 1, rep + (word1[i] != word2[j]));
            }
        }

        return dp[word1.length() - 1][word2.length() - 1];
    }
};
// @lc code=end

/**
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        if (n1 == 0 || n2 == 0) return max(n1, n2);
        
        vector<vector<int>> opt;
        for (int i = 0; i <= n1; i++) {
            vector<int> line(n2 + 1, 0);
            opt.push_back(line);
        }
        for (int j = 0; j <= n2; j++) {
            opt[0][j] = j;
        }
        for (int i = 0; i <= n1; i++) {
            opt[i][0] = i;
        }
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i-1] == word2[j-1]) {
                    opt[i][j] = opt[i-1][j-1];
                } else {
                    opt[i][j] = min(min(opt[i-1][j], opt[i][j-1]), opt[i-1][j-1]) + 1;
                }
            }
        }
        return opt[word1.size()][word2.size()];
    }
};
**/
