class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<int, set<string>> m;
        unordered_map<string, int> count;
        for (const auto& w : words) {
            m[count[w]].erase(w);
            count[w]++;
            m[count[w]].insert(w);
        }
        vector<string> v;
        auto it = m.rbegin();
        while (it != m.rend()) {
            for (auto e : it->second) {
                v.push_back(e);
                k--;
                if (k == 0) return v;
            }
            it++;
        }
        return v;
    }
};
