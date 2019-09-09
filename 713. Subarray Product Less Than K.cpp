class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        vector<int> opt(nums.size(), 0);

        int count = 0;
        int last = 1;
        for (int i = 0; i < nums.size(); i++) {
            last = last * nums[i];
            int n = (i == 0) ? 0 : opt[i - 1];
            if (last >= k) {
                while ((n <= i) && (last >= k)) {
                    last /= nums[n];
                    n++;
                }
                if (n > i) {
                    opt[i] = i + 1;
                    continue;
                }
            }

            opt[i] = n;
            count += i - n + 1;
        }

        return count;
    }
};
