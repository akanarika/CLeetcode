/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, int> color; // 1, -1
        for (int i = 0; i < graph.size(); i++) {
            if (color.find(i) == color.end()) {
                color[i] = 1;
                if (!colorGraph(i, graph, color)) return false;
            }
        }
        return true;
    }

    bool colorGraph(int i, vector<vector<int>>& g, unordered_map<int, int>& color) {
        for (auto j : g[i]) {
            if (color.find(j) == color.end()) {
                color[j] = -color[i];
                if (!colorGraph(j, g, color)) return false;
            } else {
                if (color[j] == color[i]) return false;
            }
        }
        return true;
    }
};
// @lc code=end
