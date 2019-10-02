class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        vector<int> lmost;
        vector<int> rmost;
        int most = 0;
        for (int i = 0; i < height.size(); i++) {
            lmost.push_back(most);
            most = max(height[i], most);
        }
        most = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            rmost.push_back(most);
            most = max(height[i], most);
        }

        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            if ((lmost[i] > height[i]) && (rmost[height.size() - 1 - i] > height[i])) {
                res += min(lmost[i], rmost[height.size() - 1 - i]) - height[i];
            }
        }
        return res;
    }
};

/**
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
**/

