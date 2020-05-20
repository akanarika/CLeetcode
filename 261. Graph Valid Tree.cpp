class Solution {
private:
    bool hasCycle(vector<vector<int>>& es, int node, int parent, vector<int>& seen) {
        if (seen[node]) return true;
        seen[node] = 1;
        for (const auto& c : es[node]) {
            if (c != parent && hasCycle(es, c, node, seen)) return true;
        }
        return false;
    }
    
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> es(n);
        for (const auto& e : edges) {
            int a = e[0];
            int b = e[1];
            es[a].push_back(b);
            es[b].push_back(a);
        }
        
        vector<int> seen(n, 0);
        if (hasCycle(es, 0, -1, seen)) return false;
        
        return count(seen.begin(), seen.end(), 1) == n;
    }
};
