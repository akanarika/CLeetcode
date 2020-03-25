class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int allVisited = (1 << graph.size()) - 1;
        unordered_set<int> visited; // node << 16 | state
        queue<pair<int, int>> q;
        for (int i = 0; i < graph.size(); i++) {
            int curr = (1 << i);
            q.emplace(i, curr);
        }
        int step = 0;
        while (!q.empty()) {
            int cnt = q.size();
            while (cnt-- > 0) {
                int node = q.front().first;
                int curr = q.front().second;
                q.pop();
                if (curr == allVisited) return step;
                if (visited.count((node << 16) | curr)) continue;
                for (const auto& neighbor : graph[node]) {
                    int state = curr | (1 << neighbor);
                    q.emplace(neighbor, state);
                }
                visited.insert((node << 16) | curr);
            }
            step++;
        }
        return -1;
    }
};

/**
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
**/
