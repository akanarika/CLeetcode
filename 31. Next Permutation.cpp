class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int lastSmaller = -1;
        int smallest = -1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                lastSmaller = i;
                smallest = i + 1;
            }
            if ((lastSmaller >= 0) && (i + 1 > lastSmaller) && (nums[i + 1] < nums[smallest]) && (nums[i + 1] > nums[lastSmaller])) {
                smallest = i + 1;
            }
        }
        if (lastSmaller >= 0) {
            swap(nums[lastSmaller], nums[smallest]);
            sort(nums.begin() + lastSmaller + 1, nums.end());
        } else {
            sort(nums.begin(), nums.end());
        }
    }
};
