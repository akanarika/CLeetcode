class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.empty()) return -1;

        int s = 1;
        int e = nums.size();
        int m = 1;
        while (s < e) {
            m = (s + e) / 2;
            int count = 0;
            for (const auto& num : nums) {
                if (num <= m) count++;
            }
            if (count > m) e = m;
            else s = m + 1;
        }

        return s;
    }
};
