/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty()) return {};
        int l = words[0].size();
        int len = l * words.size();
        int n = s.length();
        unordered_map<string, int> wordCount;
        for (auto w : words) wordCount[w]++;

        int i = 0;
        vector<int> res;
        while (i <= n - len) {
            int j = i;
            string currWord = s.substr(j, l);
            unordered_map<string, int> currCount = wordCount;
            while (currCount[currWord] > 0) {
                currCount[currWord]--;
                j += l;
                if (j == i + len) {
                    res.push_back(i);
                    break;
                }
                currWord = s.substr(j, l);
            }
            i++;
        }
        return res;
    }
};
// @lc code=end
