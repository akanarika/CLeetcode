class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> m;
        for (const auto& s : strings) {
            string key = "";
            for (int i = 1; i < s.length(); i++) {
                key += "," + to_string((s[i] - s[i - 1] + 26) % 26);
            }
            m[key].push_back(s);
        }
        
        vector<vector<string>> res;
        for (const auto& p : m) {
            res.push_back(p.second);
        }
        return res;
    }
};
