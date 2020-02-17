class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size());
    }
    
    int findMin(vector<int>& nums, int low, int high) {
        if (low == high || low == high - 1 || nums[low] < nums[high - 1]) return nums[low];
        int mid = (low + high) / 2;
        if (nums[mid] > nums[high - 1]) return findMin(nums, mid, high);
        if (nums[low] > nums[mid - 1]) return findMin(nums, low, mid);
        return min(findMin(nums, low, mid), findMin(nums, mid, high));
    }
};