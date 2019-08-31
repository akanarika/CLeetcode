class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        unordered_map<int, unordered_map<int, int>> m;

        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                vector<int> pa = points[i];
                vector<int> pb = points[j];
                int dist = (pa[0] - pb[0]) * (pa[0] - pb[0]) + (pa[1] - pb[1]) * (pa[1] - pb[1]);
                m[i][dist]++;
                m[j][dist]++;
            }
        }

        int res = 0;
        for (auto pair : m) {
            for (auto dist : pair.second) {
                if (dist.second >= 2) {
                    res += (dist.second - 1) * dist.second;
                }
            }
        }
       
        return res;
    }
};
