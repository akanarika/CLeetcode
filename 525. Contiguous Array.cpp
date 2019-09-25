class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, set<int>> dict;
        dict[0].insert(0);
        int diff = 0;
        int i = 1;
        int len = 0;
        for (auto num : nums) {
            if (num) diff++;
            else diff--;
            if (dict[diff].size() > 0) len = max(len, i - *(dict[diff].begin()));
            dict[diff].insert(i++);
        }
        return len;
    }
};
