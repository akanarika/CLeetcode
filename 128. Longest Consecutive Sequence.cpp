/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_map<int, unordered_set<int>> sets;
        unordered_map<int, int> key;
        size_t maxLen = 1;
        for (int num : nums) {
            if (key.find(num) == key.end()) {
                if ((num != INT_MIN) && (key.find(num - 1) != key.end())) {
                    int lessKey = key[num - 1];
                    key[num] = lessKey;
                    sets[lessKey].insert(num);
                    if ((num != INT_MAX) && (key.find(num + 1) != key.end())) {
                        int moreKey = key[num + 1];
                        for (auto otherNum : sets[moreKey]) {
                            key[otherNum] = lessKey;
                            sets[lessKey].insert(otherNum);
                        }
                    }
                    maxLen = max(maxLen, sets[lessKey].size());
                } else if ((num != INT_MAX) && (key.find(num + 1) != key.end())) {
                    int moreKey = key[num + 1];
                    key[num] = moreKey;
                    sets[moreKey].insert(num);
                    maxLen = max(maxLen, sets[moreKey].size());
                } else {
                    key[num] = num;
                    sets[num].insert(num);
                }
            }
        }
        return maxLen;
    }
};
// @lc code=end
