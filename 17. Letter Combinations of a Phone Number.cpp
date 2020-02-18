/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
private:
    vector<string> dic = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void addString(string digits, string curr, int i, vector<string>& res) {
        for (auto c : dic[digits[i] - '2']) {
            if (i == digits.size() - 1) {
                res.push_back(curr + c);
                continue;
            }
            addString(digits, curr + c, i + 1, res);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        addString(digits, "", 0, res);
        return res;
    }
};
// @lc code=end

/**
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> dict{{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"},
                                        {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
        vector<string> res;
        for (int i = 0; i < digits.size(); i++) {
            string s = dict[digits[i] - '0'];
            vector<string> new_res;
            for (int j = 0; j < s.size(); j++) {
                if (res.size() == 0) {
                    new_res.push_back(s.substr(j, 1));
                }
                for (int k = 0; k < res.size(); k++) {
                    new_res.push_back(res[k] + s.substr(j, 1));
                }
            }
            res = new_res;
        }
        return res;
    }
};
**/
