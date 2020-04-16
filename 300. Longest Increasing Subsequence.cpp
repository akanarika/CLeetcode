class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        map<int, int> m;
        int res = 0;
        for (const auto& num : nums) {
            int longest = 1;
            for (auto it = m.begin(); it != m.end() && it->first < num; it++) {
                longest = max(longest, 1 + it->second);
            }
            m[num] = longest;
            res = max(res, longest);
        }
        return res;
    }
};

/**
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        map<int, int> l;
        int m = 0;
        for (auto num : nums) {
            l[num] = 1;
            auto found = l.lower_bound(num);
            if (found != l.end() && found != l.begin()) {
                while (true) {
                    found--;
                    l[num] = max(l[num], found->second + 1);
                    if (found == l.begin()) break;
                }
            }
            m = max(m, l[num]);
        }
        return m;
    }
};
**/
