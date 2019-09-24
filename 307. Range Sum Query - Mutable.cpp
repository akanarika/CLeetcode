class NumArray {
    vector<int> sums;
    vector<int> _nums;
    int n;
public:
    NumArray(vector<int>& nums) {
        _nums = nums;
        n = nums.size() + 1;
        sums = vector<int>(n, 0);
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            while (j < n) {
                sums[j] += nums[i];
                j += j & (-j);
            }
        }
    }
    
    void update(int i, int val) {
        int diff = val - _nums[i];
        _nums[i] = val;
        int j = i + 1;
        while (j < n) {
            sums[j] += diff;
            j += j & (-j);
        }
    }
    
    int sumRange(int i, int j) {
        int k = j + 1;
        int sum1 = 0;
        while (k > 0) {
            sum1 += sums[k];
            k -= k & (-k);
        }
        k = i;
        int sum2 = 0;
        while (k > 0) {
            sum2 += sums[k];
            k -= k & (-k);
        }
        return sum1 - sum2;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
