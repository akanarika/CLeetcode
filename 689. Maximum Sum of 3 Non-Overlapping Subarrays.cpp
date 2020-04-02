class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxSum = {0, 0, 0, 0};
        vector<int> sums(n, 0);
        vector<vector<int>> sum1(n);
        int currSum = 0;
        for (int i = n - 1; i >= 0; i--) {
            currSum += nums[i];
            if (i + k < n) currSum -= nums[i + k];
            if (currSum >= maxSum[0]) {
                maxSum[0] = currSum;
                maxSum[3] = i;
            }
            if (i + k <= n) {
                sums[i] = currSum;
                sum1[i] = maxSum;
            }
        }
        
        vector<int> sums2(n, 0);
        vector<vector<int>> sum2(n);
        maxSum = {0, 0, 0, 0};
        currSum = 0;
        for (int i = n - 2 * k; i >= 0; i--) {
            currSum = sums[i] + sum1[i + k][0];
            if (currSum >= maxSum[0]) {
                maxSum[0] = currSum;
                maxSum[2] = i;
                maxSum[3] = sum1[i + k][3];
            }
            sum2[i] = maxSum;
            sums2[i] = currSum;
        }
        
        maxSum = {0, 0, 0, 0};
        currSum = 0;
        for (int i = n - 3 * k; i >= 0; i--) {
            currSum = sums[i] + sum2[i + k][0];
            if (currSum >= maxSum[0]) {
                maxSum[0] = currSum;
                maxSum[1] = i;
                maxSum[2] = sum2[i + k][2];
                maxSum[3] = sum2[i + k][3];
            }
        }
        return vector<int>(maxSum.begin() + 1, maxSum.end());
    }
};
