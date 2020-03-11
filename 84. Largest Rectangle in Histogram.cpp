class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> idx;
        int res = 0;
        heights.push_back(0);
        int i = 0;
        while (i < heights.size()) {
            if (!idx.empty() && heights[i] < heights[idx.top()]) {
                int h = heights[idx.top()];
                idx.pop();
                res = max(res, h * (idx.empty() ? i : (i - 1 - idx.top())));
            } else {
                idx.push(i++);
            }
        }
        return res;
    }
};