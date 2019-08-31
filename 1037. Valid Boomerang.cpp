class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        vector<int> a = points[0];
        vector<int> b = points[1];
        vector<int> c = points[2];
        if (a == b || b == c || a == c) return false;

        if (a[0] == b[0]) return c[0] != a[0];

        return !((a[0] - b[0]) * (a[1] - c[1]) == (a[0] - c[0]) * (a[1] - b[1])) ||
            !((b[0] - a[0]) * (a[1] * c[0] - c[1] * a[0]) == (c[0] - a[0]) * (a[1] * b[0] - b[1] * a[0]));
    }
};
