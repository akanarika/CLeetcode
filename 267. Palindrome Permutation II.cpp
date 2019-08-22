class Solution {
public:
    vector<string> generatePalindromes(string s) {
        if (s.empty()) return {};
        if (s.length() == 1) return {s};
        map<char, int> count;
        for (const auto& c : s) {
            count[c]++;
        }
        string base = "";
        string odd = "";
        unordered_map<string, unordered_set<string>> m;
        for (auto& pair : count) {
            if (pair.second % 2 == 1) {
                if (!odd.empty()) return {};
                else {
                    odd = string(1, pair.first);
                    pair.second= pair.second - 1;
                }
            }
            for (int i = 0; i < pair.second / 2; i++) {
                base += pair.first;
            }
            m[string(1, pair.first)] = {string(1, pair.first)};
        }
        
        unordered_set<string> sset = constructString(base, m);

        vector<string> res;
        for (auto str : sset) {
            string combine = str + odd;
            reverse(str.begin(), str.end());
            combine += str;
            res.push_back(combine);
        }
        return res;
    }

    unordered_set<string> constructString(string s, unordered_map<string, unordered_set<string>>& m) {
        unordered_set<string> sset;
        if (m.find(s) != m.end()) return m[s];
        for (size_t i = 0; i < s.size(); i++) {
            for (auto str : constructString(s.substr(0, i) + s.substr(i + 1, s.length() - i - 1), m)) {
                sset.insert(s[i] + str);
            }
        }
        m[s] = sset;
        return sset;
    }
};
