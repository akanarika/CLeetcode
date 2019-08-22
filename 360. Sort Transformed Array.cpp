class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        if (a == 0) {
            vector<int> res;
            for (auto& num : nums) {
                if (b > 0) res.push_back(b * num + c);
                else res.insert(res.begin(), b * num + c);
            }
            return res;
        }

        vector<int> res;
        double mid = 2 * a;
        mid = -(b / mid);
        int l, r;
        l = r = 0;
        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] >= mid) && (i == 0 || nums[i - 1] < mid)) {
                r = i;
                l = i - 1;
                break;
            }
            r = nums.size();
            l = nums.size() - 1;
        }
       
        while ((l >= 0) || (r < nums.size())) {
            int val;
            if ((l >= 0) && (r < nums.size())) {
                if ((mid - nums[l]) < (nums[r] - mid)) {
                    val = nums[l];
                    l--;
                } else {
                    val = nums[r];
                    r++;
                }
            } else if (l >= 0) {
                val = nums[l];
                l--;
            } else {
                val = nums[r];
                r++;
            }
            if (a > 0) res.push_back(a * val * val + b * val + c);
            else res.insert(res.begin(), a * val * val + b * val + c);
        }
        return res; 
    }
};
