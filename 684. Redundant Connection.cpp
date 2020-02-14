class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size() + 1, 0);
        
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            if (!parent[u]) {
                parent[u] = u;
            }
            if (!parent[v]) {
                parent[v] = v;
            }
            
            int pu = find(u, parent);
            int pv = find(v, parent);
            if (pu == pv) return edge;
            
            parent[pu] = pv;
        }
        
        return {};
    }
private:
    int find(int u, vector<int>& parent) {
        while (parent[u] != u) {
            parent[u] = parent[parent[u]];
            u = parent[u];
        }
        return u;
    }
};

/**
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
**/