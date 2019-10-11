class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (auto& num : nums) {
            if (num < 0) num = 0;
        }

        int i = 0;
        while (i < nums.size()) {
            if ((nums[i] > 0) && (nums[i] != i + 1)) {
                if ((nums[i] - 1 < nums.size()) && (nums[i] - 1 >= 0)) {
                    int tmp = nums[nums[i] - 1];
                    if (tmp == -1) {
                        nums[i] = 0;
                        i++;
                        continue;
                    }
                    nums[nums[i] - 1] = -1;
                    nums[i] = tmp;
                } else {
                    i++;
                }
            } else if (nums[i] == i + 1) {
                nums[i] = -1;
                i++;
            } else {
                i++;
            }
        }

        i = 0;
        for (auto num : nums) {
            if (num != -1) {
                return i + 1;
            }
            i++;
        }

        return nums.size() + 1;
    }
};
