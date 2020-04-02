class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // optimize
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> res;
        for (const auto& num : nums2) {
            if (s.erase(num)) res.push_back(num);
            // optimize
            if (s.empty()) return res;
        }
        return res;
    }
};

/**
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> res;

        for (auto num : nums2) {
            if (s.count(num)) {
                s.erase(num);
                res.push_back(num);
            }
        }
        return res;
    }
};
**/
