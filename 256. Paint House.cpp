class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        
        int n = costs.size();
        vector<int> tmp;
        vector<vector<int>> m(n, tmp);
        
        m[n - 1].push_back(costs[n - 1][0]);
        m[n - 1].push_back(costs[n - 1][1]);
        m[n - 1].push_back(costs[n - 1][2]);
        
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < 3; j++) {
                m[i].push_back(costs[i][0] + min(m[i + 1][1], m[i + 1][2]));
                m[i].push_back(costs[i][1] + min(m[i + 1][0], m[i + 1][2]));
                m[i].push_back(costs[i][2] + min(m[i + 1][0], m[i + 1][1]));
            }
        }    
        
        return min(min(m[0][0], m[0][1]), m[0][2]);
    }
};