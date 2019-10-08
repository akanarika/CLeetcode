class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        while (s <= e) {
            int m = (s + e) / 2;
            if (nums[m] < target) {
                if (nums[e] > target) {
                    s = m + 1;
                } else if (nums[e] < target) {
                    if (nums[m] < nums[e]) e = m;
                    else s = m + 1;
                } else return e;
            } else if (nums[m] > target) {
                if (nums[s] < target) {
                    e = m;
                } else if (nums[s] > target) {
                    if (nums[s] > nums[m]) e = m;
                    else s = m + 1;
                } else return s;
            } else return m;
        }
        return -1;
    }
};