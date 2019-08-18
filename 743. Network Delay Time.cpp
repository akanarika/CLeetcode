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
