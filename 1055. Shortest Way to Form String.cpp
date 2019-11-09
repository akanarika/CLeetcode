/*
 * @lc app=leetcode id=1055 lang=cpp
 *
 * [1055] Shortest Way to Form String
 */

// @lc code=start
class Solution {
public:
    int shortestWay(string source, string target) {
        vector<set<int>> v(26, set<int>());
        for (int i = 0; i < source.size(); i++) {
            v[source[i] - 'a'].insert(i);
        }

        int j = 0;
        int count = 1;
        for (int i = 0; i < target.length(); i++) {
            set<int> cset = v[target[i] - 'a'];
            if (cset.size() == 0) return -1;
            auto found = (i == 0 ? cset.begin() : cset.upper_bound(j));
            if (found == cset.end()) {
                count++;
                j = *(cset.begin());
            } else {
                j = *found;
            }
        }

        return count;
    }
};
// @lc code=end
