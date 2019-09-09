class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 1) return triangle[0][0];
        int res = INT_MAX;
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                int left = (j == 0) ? INT_MAX : triangle[i - 1][j - 1];
                int right = (j == triangle[i].size() - 1) ? INT_MAX : triangle[i - 1][j];
                triangle[i][j] += min(left, right);
                if (i == triangle.size() - 1) res = min(res, triangle[i][j]);
            }
        }
        return res; 
    }
};
