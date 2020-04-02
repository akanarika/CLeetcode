class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        nth_element(points.begin(), points.begin() + K - 1, points.end(), [](vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};

/**
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        map<int, vector<vector<int>>> dist;
        for (auto p : points) {
            dist[p[0] * p[0] + p[1] * p[1]].push_back(p);
        }
        
        auto it = dist.begin();
        vector<vector<int>> res;
        while (K > 0) {
            res.insert(res.end(), it->second.begin(), it->second.end());
            K -= it->second.size();
            it++;
        }
        return res;
    }
};
**/
