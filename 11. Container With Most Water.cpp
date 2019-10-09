class Solution {
public:
    int maxArea(vector<int>& height) {
        int p1 = 0;
        int p2 = height.size() - 1;
        int max_area = min(height[p1], height[p2]) * (p2 - p1);
        while (1) {
            if (height[p1] < height[p2]) {
                p1++;
            } else {
                p2--;
            }
            if (p1 >= p2) break;
            max_area = max(max_area, min(height[p1], height[p2]) * (p2 - p1));
        }
        
        return max_area;
    }
};

/**
class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 2) return 0;

        int p = 0;
        int q = height.size() - 1;
        int left = height[p];
        int right = height[q];
        int maxArea = 0;
        while (p < q) {
            maxArea = max(maxArea, (q - p) * min(left, right));
            if (left <= right) {
                p++;
                if (height[p] > left) {
                    left = height[p];
                }
            } else {
                q--;
                if (height[q] > right) {
                    right = height[q];
                }
            }
        }
        return maxArea;
    }
};
**/

