class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> idx;
        vector<int> evens;
        int curr = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & 1) {
                idx.push_back(i);
                evens.push_back(curr);
                curr = 0;
            } else {
                curr++;
            }
        }
        evens.push_back(curr);
        
        int cnt = 0;
        for (int i = 0; i < idx.size(); i++) {
            if (i + k <= idx.size()) {
                cnt += (1 + evens[i]) * (1 + evens[i + k]);
            }
        }
        
        return cnt;
    }
};