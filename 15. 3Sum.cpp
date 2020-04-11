class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};
        sort(nums.begin(), nums.end());
        int i = 0;
        int n = nums.size();
        vector<vector<int>> res;
        while (i <= n - 3) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum2 = nums[j] + nums[k];
                if (sum2 < -nums[i]) {
                    j++;
                } else if (sum2 > -nums[i]) {
                    k--;
                } else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while ((j < k) && (nums[j] == nums[j - 1])) j++;
                }
            }
            i++;
            while ((i < n) && (nums[i] == nums[i - 1])) i++;
        }
        return res;
    }
};

/**
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            if ((i > 0) && (nums[i] == nums[i - 1])) continue;
            int s = i + 1;
            int e = nums.size() - 1;
            int target = -nums[i];
            while (s < e) {
                if (nums[s] + nums[e] < target) s++;
                else if (nums[s] + nums[e] > target) e--;
                else {
                    vector<int> trip = {nums[i], nums[s], nums[e]};
                    while ((s < e) && (nums[s] == trip[1])) {
                        s++;
                    }
                    while ((s < e) && (nums[e] == trip[2])) {
                        e--;
                    }
                    res.push_back(trip);
                }
            }
        }

        return res;
    }
};
**/
