/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */

// @lc code=start
class NumArray {
private:
    vector<int> numarr;
    vector<int> sums;
    int N;
public:
    NumArray(vector<int>& nums) {
        N = nums.size();
        sums = vector<int>(N + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            int idx = i + 1;
            while (idx <= N) {
                sums[idx] += nums[i];
                idx += idx & (-idx);
            }
        }
        numarr = nums;
    }
    
    void update(int i, int val) {
        int diff = val - numarr[i];
        numarr[i] = val;
        int idx = i + 1;
        while (idx <= N) {
            sums[idx] += diff;
            idx += idx & (-idx);
        }
    }
    
    int sumRange(int i, int j) {
        return query(j) - query(i - 1);
    }

    int query(int i) {
        int idx = i + 1;
        int s = 0;
        while (idx > 0) {
            s += sums[idx];
            idx -= idx & (-idx);
        }
        return s;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
// @lc code=end

/**
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
**/

