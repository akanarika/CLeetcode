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
