class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKth(nums, 0, nums.size() - 1, 1 + nums.size() - k);
    }
private:
    int findKth(vector<int>& nums, int s, int e, int k) {
        int pivot = nums[e];
        int i = s - 1;
        for (int j = s; j <= e - 1; j++) {
            if (nums[j] < pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[e]);
        if (k - 1 > i + 1) return findKth(nums, i + 2, e, k);
        if (k - 1 < i + 1) return findKth(nums, s, i, k);
        return nums[i + 1];
    }
};

/**
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        nth_element(nums.begin(), nums.begin() + k, nums.end());
        return *(nums.begin() + k);
    }
};
 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for (int i = 0; i < nums.size(); i++) {
            q.push(nums[i]);
        }
        int res;
        while (k > 0) {
            res = q.top();
            q.pop();
            k--;
        }
        
        return res;
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> kNums;
        for (const auto& num : nums) {
            if ((kNums.size() < k) || (num > kNums.top())) {
                kNums.push(num);
                while (kNums.size() > k) {
                    kNums.pop();
                }
            }
        }
        return kNums.top();
    }
};
// @lc code=end
