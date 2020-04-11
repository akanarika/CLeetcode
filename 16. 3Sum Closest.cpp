class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mindiff = INT_MAX;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int t = target - nums[i];
            int p = i + 1;
            int q = nums.size() - 1;
            while (p < q) {
                int currdiff = abs(nums[p] + nums[q] - t);
                if (currdiff < mindiff) {
                    mindiff = currdiff;
                    res = nums[p] + nums[q] + nums[i];
                }
                if (t < nums[p] + nums[q]) {
                    q--;
                } else if (t > nums[p] + nums[q]) {
                    p++;
                } else return target;
            }
        }
        return res;
    }
};

/**
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int p1 = 0;
        int p2 = 1;
        int p3 = n - 1;

        int closest = 0;
        int currDiff = INT_MAX;
        while (p1 < n - 2) {
            int num1 = nums[p1];
            while (p2 < p3) {
                int sum = num1 + nums[p2] + nums[p3];
                int diff = abs(sum - target);
                if (diff < currDiff) {
                    closest = sum;
                    currDiff = diff;
                }

                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    p2++;
                } else {
                    p3--;
                }
            }
            p1++;
            p2 = p1 + 1;
            p3 = n - 1;
        }
        return closest;
    }
};
**/
