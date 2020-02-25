/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
class NumArray {
private:
    int N;
    vector<int> sums;
public:
    NumArray(vector<int>& nums) {
        N = nums.size();
        sums = vector<int>(N, 0);
        int sum = 0;
        int i = 0;
        for (auto num : nums) {
            sum += num;
            sums[i++] = sum;
        }
    }
    
    int sumRange(int i, int j) {
        return sums[j] - (i > 0 ? sums[i - 1] : 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end
