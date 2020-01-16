/*
 * @lc app=leetcode id=1170 lang=cpp
 *
 * [1170] Compare Strings by Frequency of the Smallest Character
 */

// @lc code=start
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> res;
        vector<int> wi;
        for (auto w : words) wi.push_back(f(w));
        map<int, int> count;
        for (auto i : wi) {
            count[i]++;
        }
        int last = 0;
        for (auto it = count.rbegin(); it != count.rend(); it++) {
            it->second += last;
            last = it->second;
        }
        for (auto q : queries) {
            int c = f(q);
            res.push_back(count.upper_bound(c)->second);
        }
        return res;
    }
    
    int f(string word) {
        map<char, int> m;
        for (auto c : word) {
            m[c]++;
        }
        return m.begin()->second;
    }
};
// @lc code=end
