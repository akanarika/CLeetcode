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