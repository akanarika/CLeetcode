/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        for (auto w : wordList) dict.insert(w);

        vector<string> level = {beginWord};
        unordered_set<string> seen;
        int step = 0;
        while (!level.empty()) {
            vector<string> newLevel;
            step++;
            for (auto w : level) {
                if (w == endWord) return step;
                for (int i = 0; i < w.size(); i++) {
                    char c =  w[i];
                    for (int j = 0; j <= 25; j++) {
                        if ('a' + j == c) continue;
                        w[i] = 'a' + j;
                        if (dict.count(w) && !seen.count(w)) {
                            seen.insert(w);
                            newLevel.push_back(w);
                        }
                    }
                    w[i] = c;
                }
            }
            swap(level, newLevel);
        }
        return 0;
    }
};
// @lc code=end
