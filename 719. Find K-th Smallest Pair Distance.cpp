class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0;
        int high = nums[n - 1] - nums[0];
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            int count = 0;
            for (auto it = nums.begin(); it != nums.end(); it++) {
                int d = distance(it, upper_bound(nums.begin(), nums.end(), *it + mid));
                count += d - 1;
            }
            
            if (count >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};