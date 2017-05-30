class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        int left = 0;
        int right = height.size() - 1;
        int max_left = height[left];
        int max_right = height[right];
        int res = 0;
        while (left < right) {
            if (max_left < max_right) {
                res += max_left - height[left];
                left++;
                max_left = max(max_left, height[left]);
            } else {
                res += max_right - height[right];
                right--;
                max_right = max(max_right, height[right]);
            }
        }
        
        return res;
    }
};