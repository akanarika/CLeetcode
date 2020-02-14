class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums[0];
        int count = 0;
        for (const auto& num : nums) {
            if (maj == num) count++;
            else if (--count == 0) {
                count = 1;
                maj = num;
            }
        }
        return maj;
    }
};

/**class Solution {
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
**/