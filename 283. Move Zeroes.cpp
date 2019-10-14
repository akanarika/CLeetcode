/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p = 0;
        int q = 0;
        while (q < nums.size()) {
            if (nums[q] == 0) {
                q++;
            } else {
                if (p != q) nums[p] = nums[q];
                p++;
                q++;
            }
        }
        while (p < nums.size()) {
            nums[p++] = 0;
        }
    }
};
// @lc code=end
/**
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i;
        int n = 0;
        vector<int>::iterator it = nums.begin();
        while (it != nums.end()) {
            if (*it == 0) {
                n++;
                nums.erase(it);
            } else {
                it++;
            }
        }
        while (n) {
            nums.push_back(0);
            n--;
        }
    }
};
**/
