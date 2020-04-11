class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size()) swap(nums1, nums2);
        multiset<int> ms(nums2.begin(), nums2.end());
        
        vector<int> res;
        for (const auto& num : nums1) {
            if (ms.count(num)) {
                res.push_back(num);
                ms.erase(ms.equal_range(num).first);
            }
        }
        return res;
    }
};
