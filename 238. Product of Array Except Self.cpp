class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int num = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            res.push_back(num);
            num *= nums[i];
        }
        
        num = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] *= num;
            num *= nums[i];
        }
        
        return res;
    }
};