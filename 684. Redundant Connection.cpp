class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> sets;
        vector<int> res;
        for (auto e : edges) {
            if (sets.find(e[0]) == sets.end() && sets.find(e[1]) == sets.end()) {
                unordered_set<int> set = {e[0], e[1]};
                sets[e[0]] = sets[e[1]] = set;
            } else {
                if (sets[e[0]] == sets[e[1]]) {
                    res = e;
                    continue;
                }
                for (auto i : sets[e[0]]) {
                    sets[e[1]].insert(i);
                }
                sets[e[1]].insert(e[0]);
                sets[e[1]].insert(e[1]);
                for (auto i : sets[e[1]]) {
                    sets[i] = sets[e[1]];
                }
            }
        }

        return res;
    }
};
