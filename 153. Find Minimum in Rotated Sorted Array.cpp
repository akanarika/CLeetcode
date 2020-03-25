class Solution {
private:
    int findMin(vector<int>& nums, int low, int high) {
        if (high == low) return nums[low];
        if (nums[high - 1] >= nums[low]) return nums[low];
        
        int mid = low + (high - low) / 2;
        return min(findMin(nums, low, mid), findMin(nums, mid, high));
    }
    
public:
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size());
    }
};

/**
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
**/
