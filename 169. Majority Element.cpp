class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> d;
        int i;
        for (i = 0; i < nums.size(); i++) {
            if (d.find(nums[i]) != d.end()) d[nums[i]]++;
            else d[nums[i]] = 1;
            if (d[nums[i]] > (nums.size() / 2)) return nums[i];
        }
        
    }
};