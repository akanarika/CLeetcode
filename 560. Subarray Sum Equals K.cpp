class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int curr = 0;
        int res = 0;
        m[k] = 1;
        for (auto num : nums) {
            curr += num;
            res += m[curr];
            m[curr + k]++;
        }
        return res;
    }
};
