/*
 * @lc app=leetcode id=616 lang=cpp
 *
 * [616] Add Bold Tag in String
 */

// @lc code=start
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        unordered_set<string> words;
        for (const auto& word : dict) {
            words.insert(word);
        }
        
        int n = s.length();
        vector<pair<int, int>> res;
        for (int i = 0; i < n; i++) {
            int currright = 0;
            string sub = "";
            for (int len = 1; i + len <= n; len++) {
                sub += s[i + len - 1];
                if (words.count(sub)) {
                    if (res.empty()) res.push_back(make_pair(i, i + len));
                    else if (res.back().first == i || res.back().second >= i) {
                        res.back().second = max(res.back().second, i + len);
                    } else {
                        res.push_back(make_pair(i, i + len));
                    }
                }
            }
        }
        
        int i = 0;
        for (const auto& pr : res) {
            int left = pr.first;
            s.insert(i + left, "<b>");
            i += 3;
            int right = pr.second;
            s.insert(i + right, "</b>");
            i += 4;
        }
        return s;
    }
};
// @lc code=end
