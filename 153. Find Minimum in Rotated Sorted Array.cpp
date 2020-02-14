class Solution {
public:
    int findMin(vector<int>& nums) {
        return find(nums, 0, nums.size());
    }
    
private:
    int find(vector<int>& nums, int left, int right) {
        if (left == right || left == right - 1 || nums[left] < nums[right - 1]) return nums[left];
        
        int mid = (left + right) / 2;
        if (nums[left] <= nums[mid - 1] && nums[mid] <= nums[right - 1]) return nums[mid];
        if (nums[left] < nums[mid]) return find(nums, mid, right);
        if (nums[mid] < nums[right - 1]) return find(nums, left, mid);
        return -1;
    }
};