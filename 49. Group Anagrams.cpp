class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dict;
        for (auto s: strs) {
            string ori = s;
            sort(s.begin(), s.end());
            dict[s].push_back(ori);
        }
        vector<vector<string>> res;
        for (auto it = dict.begin(); it != dict.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};