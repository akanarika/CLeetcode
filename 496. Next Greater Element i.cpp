class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        for (auto &num1 : nums1) {
            for (auto it = find(nums2.begin(), nums2.end(), num1); it != nums2.end(); it++) {
                if ((it == nums2.end() - 1) && (*it <= num1)) {
                    num1 = -1;
                } else if(*it > num1) {
                    num1 = *it;
                    break;
                }
            }
        }

        return nums1;
    }
};
