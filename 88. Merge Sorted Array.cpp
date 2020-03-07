class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = nums1.size();
        for (int i = 0; i < m; i++) {
            nums1[l - i - 1] = nums1[m - i - 1];
        }
        int p1 = l - m;
        int p2 = 0;
        int i = 0;
        while (p1 < l && p2 < n) {
            if(nums1[p1] < nums2[p2]) {
                nums1[i++] = nums1[p1++];
            } else {
                nums1[i++] = nums2[p2++];
            }
        }
        
        while (p2 < n) {
            nums1[i++] = nums2[p2++];
        }
    }
};