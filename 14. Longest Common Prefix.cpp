class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string res = "";
        for (int i = 0; i < strs[0].size(); i++) {
            char curr = strs[0][i];
            for (int j = 0; j < strs.size(); j++) {
                if (curr != strs[j][i]) {
                    return res;
                }
            }
            res = strs[0].substr(0, i + 1);
        }
        return res;
    }
};