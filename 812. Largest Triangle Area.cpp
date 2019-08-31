class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double res = 0;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                for (int k = j + 1; k < points.size(); k++) {
                    res = max(area(points[i], points[j], points[k]), res);
                }
            }
        }
        return res;
    }

    double area(vector<int>& a, vector<int>& b, vector<int>& c) {
        double tmp = (a[0] * (b[1] - c[1]) + b[0] * (c[1] - a[1]) + c[0] * (a[1] - b[1])); 
        tmp = (tmp < 0) ? (-tmp) : tmp;
        return tmp / 2;

    }
};
