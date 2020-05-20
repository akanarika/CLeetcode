class Solution {
private:
    int gcd(int x, int y) {
        if (y == 0) return x;
        return gcd(y, x % y);
    }
    
    pair<int, int> slope(vector<int> p1, vector<int> p2) {
        int x = p1[0] - p2[0];
        int y = p1[1] - p2[1];
        if (y == 0) return make_pair(1, 0);
        if (x == 0) return make_pair(0, 1);
        int d = gcd(x, y);
        return make_pair(x / d, y / d);
    }
    
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        
        int n = points.size();
        int res = 1;
        for (int i = 0; i < n; i++) {
            auto p1 = points[i];
            int dup = 1;
            map<pair<int, int>, int> cnt;
            int maxcnt = 0;
            for (int j = i + 1; j < n; j++) {
                auto p2 = points[j];
                if (p2 == p1) {
                    dup++;
                } else {
                    maxcnt = max(maxcnt, ++cnt[slope(p1, p2)]);
                }
            }
            res = max(dup + maxcnt, res);
        }
        return res;
    }
};
