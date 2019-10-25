/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if (n > m) {
            swap(n, m);
            swap(nums1, nums2);
        }

        int nn = n + n + 1;
        int mm = m + m + 1;
        int dist = n + m;
        int s = 0;
        int e = nn - 1;
        while (true) {
            int i = (s + e) / 2;
            int j = dist - i;
            int left1, right1, left2, right2;
            if (i % 2) {
                left1 = right1 = nums1[i / 2];
            } else {
                left1 = i == 0 ? INT_MIN : nums1[(i / 2) - 1];
                right1 = i == nn - 1 ? INT_MAX : nums1[i / 2];
            }
            if (j % 2) {
                left2 = right2 = nums2[j / 2];
            } else {
                left2 = j == 0 ? INT_MIN : nums2[(j / 2) - 1];
                right2 = j == mm - 1 ? INT_MAX : nums2[j / 2];
            }
            if (left1 <= right2 && left2 <= right1) {
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            } else if (left1 > right2) {
                e = i;
            } else if (left2 > right1) {
                s = i + 1;
            }
        }
        return 0;
    }
};
// @lc code=end

/**
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) {
            swap(nums1, nums2);
            swap(m, n);
        }
        int s = 0;
        int e = m;

        while (s <= e) {
            int i = (s + e) / 2;
            int j = ((m + n + 1) / 2) - i;
            if ((i > 0) && (nums1[i - 1] > nums2[j])) {
                e = i - 1;
            } else if ((i < m) && (nums2[j - 1] > nums1[i])) {
                s = i + 1;
            } else {
                int left = 0;
                if (i == 0) left = nums2[j - 1];
                else if (j == 0) left = nums1[i - 1];
                else left = max(nums2[j - 1], nums1[i - 1]);

                if ((m + n) % 2) return left;

                int right = 0;
                if (i == m) right = nums2[j];
                else if (j == n) right = nums1[i];
                else right = min(nums2[j], nums1[i]);

                return (left + right) / 2.0;
            }
        }

        return 0;
    }
};

 **/
