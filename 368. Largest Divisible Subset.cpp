class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};

        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> m;

        for (auto num : nums) {
            m[num] = {num};
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] % nums[i] == 0) {
                    if (m[nums[i]].size() + 1 > m[nums[j]].size()) {
                        m[nums[j]] = m[nums[i]];
                        m[nums[j]].push_back(nums[j]);
                    }
                }
            }
        }

        size_t maxSize = 0;
        vector<int> res;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second.size() > maxSize) {
                maxSize = it->second.size();
                res = it->second;
            }
        }

        return res;
    }
};
