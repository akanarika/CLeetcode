class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return -1;
        int maxPos = -1;
        int minNeg = 1;
        int res = nums[0];
        for (const auto& num : nums) {
            int mPos = maxPos;
            int mNeg = minNeg;
            if (num > 0) {
                maxPos = (mPos > 0) ? mPos * num : num;
                minNeg = (mNeg < 0) ? mNeg * num : 1;
            } else if (num < 0) {
                maxPos = (mNeg < 0) ? mNeg * num : -1;
                minNeg = (mPos > 0) ? mPos * num : num;
            } else {
                maxPos = minNeg = 0;
            }
            if (maxPos >= 0) res = max(res, maxPos);
        }
        return res;
    }
};

/**
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> pos(nums.size(), nums[0]);
        vector<int> neg(nums.size(), nums[0]);
        int maxPro = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > 0) {
                pos[i] = max(nums[i], nums[i] * pos[i - 1]);
                neg[i] = min(nums[i], nums[i] * neg[i - 1]);
            } else {
                pos[i] = max(nums[i] * neg[i - 1], nums[i]);
                neg[i] = min(nums[i] * pos[i - 1], nums[i]);
            }
            maxPro = max(maxPro, pos[i]);
        }
        return maxPro;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        unordered_map<int, pair<int, int>> m;
        if (nums[0] > 0) m[0] = make_pair(0, nums[0]);
        else m[0] = make_pair(nums[0], 0);
        
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int l = nums[i] * (m[i - 1].first);
            int r = nums[i] * (m[i - 1].second);
            if (nums[i] > 0) {
                m[i].first = min(nums[i], l);
                m[i].second = max(nums[i], r);
                res = max(res, m[i].second);
            } else {
                m[i].first = min(nums[i], r);
                m[i].second = max(nums[i], l);
                res = max(res, m[i].second);
            }
        }
        
        return res;
    }
};
**/
 
