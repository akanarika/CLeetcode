class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int dis = 0;
        int n = nums.size();
        for (int b = 0; b < 32; b++) {
            int cnt = 0;
            int mask = 1 << b;
            for (int i = 0; i < n; i++) {
                if (nums[i] & mask) cnt++;
            }
            dis += cnt * (n - cnt);
        }
        return dis;
    }
};
