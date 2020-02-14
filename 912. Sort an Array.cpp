class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int low = 0;
        int high = nums.size();
        return sort(nums, low, high);
    }
    
private:
    vector<int> sort(vector<int>& nums, int low, int high) {
        if (low == high) return {};
        if (low == high - 1) return {nums[low]};
        int mid = (low + high) / 2;
        vector<int> left = sort(nums, low, mid);
        vector<int> right = sort(nums, mid, high);
        return merge(left, right);
    }
    
    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> res;
        int pa = 0;
        int pb = 0;
        while (pa < a.size() || pb < b.size()) {
            if (pa >= a.size() || pb < b.size() && b[pb] <= a[pa]) {
                res.push_back(b[pb++]);
            } else if (pb >= b.size() || pa < a.size() && a[pa] < b[pb]) {
                res.push_back(a[pa++]);
            }
        }
        return res;
    }
};