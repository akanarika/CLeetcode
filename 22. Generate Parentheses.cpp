/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
private:
    void generate(int left, int right, string curr, vector<string>& res, int n) {
        if (curr.size() == 2 * n) {
            res.push_back(curr);
            return;
        }

        if (left - right > 0) {
            generate(left, right + 1, curr + ")", res, n);
        }
        if (left < n) {
            generate(left + 1, right, curr + "(", res, n);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(0, 0, "", res, n);
        return res;
    }
};
// @lc code=end

/**
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int num = 0;
        unordered_map<string, int> dict{{"", 0}};
        n *= 2;
        while (n > 0) {
            unordered_map<string, int> new_dict;
            for (auto it = dict.begin(); it != dict.end(); it++) {
                if (it->second > 0) {
                    new_dict.insert({it->first + ")", it->second - 1});
                }
                new_dict.insert({it->first + "(", it->second + 1});
            }
            dict = new_dict;
            n--;
        }
        vector<string> res;
        for (auto it = dict.begin(); it != dict.end(); it++) {
            if (it->second == 0) res.push_back(it->first);
        }
        return res;
    }
};

**/
