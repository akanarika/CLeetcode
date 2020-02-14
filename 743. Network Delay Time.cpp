class Solution {
public:
    typedef pair<int, int> pi;
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int, int>>> neighbors;
        neighbors.resize(N + 1);
        for (const auto& time : times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            neighbors[u].push_back({v, w});
        }
        
        priority_queue<pi, vector<pi>, greater<pi>> q;
        vector<int> weight(N + 1, INT_MAX);
        q.push(make_pair(0, K));
        weight[K] = 0;
        while (!q.empty()) {
            auto node = q.top().second;
            q.pop();
            for (auto nei : neighbors[node]) {
                if (weight[node] + nei.second < weight[nei.first]) {
                    weight[nei.first] = weight[node] + nei.second;
                    q.push(make_pair(weight[node] + nei.second, nei.first));
                }
            }
        }
        
        int res = -1;
        for (int i = 1; i <= N; i++) {
            res = max(res, weight[i]);
        }
        
        return res == INT_MAX ? -1 : res;
    }
};

/**
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int, int> timeToNode;
        unordered_map<int, vector<vector<int>>> edges;

        for (auto time : times) {
            if (edges.find(time[0]) == edges.end()) edges[time[0]] = {};
            edges[time[0]].push_back({time[1], time[2]});
            
        }
        queue<int> nodes;
        nodes.push(K);

        timeToNode[K] = 0;
        while (!nodes.empty()) {
            int node = nodes.front();
            nodes.pop();
            for (auto edge : edges[node]) {
                if (timeToNode.find(edge[0]) == timeToNode.end() || timeToNode[edge[0]] > timeToNode[node] + edge[1]) {
                    nodes.push(edge[0]);
                    timeToNode[edge[0]] = timeToNode[node] + edge[1];
                }
            }
        }

        int maxTime = 0;
        if (timeToNode.size() != N) return -1;
        else {
            for (auto time : timeToNode) {
                maxTime = max(time.second, maxTime);
            }
        }

        return maxTime;
        
    }
};
**/