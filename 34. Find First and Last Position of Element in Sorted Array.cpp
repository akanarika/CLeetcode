class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return find(nums, target, 0, nums.size());
    }
    
private:
    vector<int> find(vector<int>& nums, int target, int s, int e) {
        if (s == e - 1 && nums[s] == target) return {s, s};
        if (s >= e - 1) return {-1, -1};
        int m = s + (e - s) / 2;
        if (nums[m] < target) return find(nums, target, m + 1, e);
        if (nums[m] > target) return find(nums, target, s, m);
        else {
            vector<int> res = {m, m};
            if (m - 1 >= s && nums[m - 1] == target) {
                auto left = find(nums, target, s, m);
                res[0] = left[0];
            }
            if (m + 1 < e && nums[m + 1] == target) {
                auto right = find(nums, target, m + 1, e);
                res[1] = right[1];
            }
            return res;
        }
    }
};

/**
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = nums.size();
        int end = -1;
        find(nums, target, 0, nums.size(), start, end);
        if (end < start || end < 0 || start >= nums.size()) return {-1, -1};
        return {start, end};
    }
    
private:
    void find(vector<int>& nums, int target, int low, int high, int& start, int& end) {
        if (low >= high) return;
        int mid = low + (high - low) / 2;
        if (nums[mid] < target) {
            find(nums, target, mid + 1, high, start, end);
        } else if (nums[mid] > target) {
            find(nums, target, low, mid, start, end);
        } else {
            int dummyend = 0;
            int dummystart = 0;
            start = min(start, mid);
            end = max(end, mid);
            find(nums, target, low, mid, start, dummyend);
            find(nums, target, mid + 1, high, dummystart, end);
        }
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        int left = search(nums, target, 0, nums.size() - 1, true);
        int right = search(nums, target, 0, nums.size() - 1, false);
        return {left, right};
    }
    int search(vector<int>& nums, int target, int s, int e, bool left) {
        if (s == e) {
            if (nums[s] == target) {
                return s;
            } else {
                return -1;
            }
        }
        int m = (s + e) / 2;
        if (nums[m] < target) {
            return search(nums, target, m + 1, e, left);
        } else if (nums[m] > target) {
            return search(nums, target, s, m, left);
        } else {
            if (left) return search(nums, target, s, m, true);
            else {
                if (m < nums.size() - 1 && nums[m + 1] != target) return m;
                return search(nums, target, m + 1, e, false);
            }
        }
    }
};
**/
