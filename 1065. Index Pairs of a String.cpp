class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        unordered_map<char, vector<string>> m;
        for (auto w : words) {
            m[w[0]].push_back(w);
        }

        set<vector<int>> s;
        int i = 0;
        while (text.length() > 0) {
            char c = text[0];
            for (const auto& sub : m[c]) {
                auto found = text.find(sub);
                if (found != string::npos) {
                    s.insert({found + i, found + i + sub.length() - 1});
                }
            }
            text = text.substr(1);
            i++;
        }

        vector<vector<int>> res;
        for (auto e : s) {
            res.push_back(e);
        }

        return res;
    }
};
