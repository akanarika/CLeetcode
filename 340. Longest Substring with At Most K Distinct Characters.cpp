class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> cnt;
        int i = 0;
        int j = 0;
        int n = s.length();
        int curr = 0;
        int res = 0;
        while (j < n) {
            char c = s[j++];
            if (cnt[c]++ > 0) res = max(res, j - i);
            else {
                curr++;
                while (curr > k) {
                    if (cnt[s[i++]]-- > 1) continue;
                    curr--;
                    break;
                }
                res = max(res, j - i);
            }
        }
        return res;
    }
};
