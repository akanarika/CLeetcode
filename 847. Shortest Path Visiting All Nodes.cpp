/*
 * @lc app=leetcode id=847 lang=cpp
 *
 * [847] Shortest Path Visiting All Nodes
 */

// @lc code=start
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        queue<tuple<int, int, int>> q;
        vector<unordered_set<int>> visited(graph.size());
        for (int i = 0; i < graph.size(); i++) {
            q.push(make_tuple(i, 1 << i, 0));
            visited[i].insert(1 << i);
        }

        int res = INT_MAX;
        while (!q.empty()) {
            int v = get<0>(q.front()); 
            int s = get<1>(q.front());
            int c = get<2>(q.front());
            q.pop();
            if (s == (1 << graph.size()) - 1) return c;
            for (auto neighbor : graph[v]) {
                int ns = (s | (1 << neighbor));
                if (visited[neighbor].count(ns)) continue;
                visited[neighbor].insert(ns);
                q.push(make_tuple(neighbor, ns, c + 1));
            }
        }
        return res;
    }
};
// @lc code=end
