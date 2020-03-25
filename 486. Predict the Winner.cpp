class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < nums.size(); i++) {
            dp[i][i] = nums[i];
        }
        for (int i = 1; i < nums.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                dp[j][i] = max(nums[j] - dp[j + 1][i],
                               nums[i] - dp[j][i - 1]);
            }
        }
        
        return dp[0][n - 1] >= 0;
    }
};

/**
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return score(0, nums.size() - 1, nums) >= 0;
    }
    
private:
    int score(int i, int j, vector<int>& nums) {
        if (i == j) return nums[i];
        return max(nums[i] - score(i + 1, j, nums),
                   nums[j] - score(i, j - 1, nums));
    }
};
**/
