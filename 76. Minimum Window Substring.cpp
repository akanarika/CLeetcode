class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> cnt;
        for (const auto& c : t) cnt[c]++;
        int total = t.length();
        
        int n = s.length();
        int i = 0;
        int j = 0;
        string res = s + "a";
        while (i < n) {
            char c = s[i++];
            cnt[c]--;
            if (cnt[c] >= 0) {
                total--;
                while (total == 0) {
                    if (i - j < res.length()) res = s.substr(j, i - j);
                    if (cnt[s[j]]++ == 0) total++;
                    j++;
                }
            }
        }
        return res.length() > n ? "" : res;
    }
};

/**
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> exist;
        int count = 0;
        for (auto c : t) {
            exist[c]++;
            count++;
        }

        string res = "";
        int start = 0;
        int end = 0;
        int minStart = 0;
        int minLen = s.length() + 1;
        while (end < s.length()) {
            char c = s[end++];
            if (exist[c]-- > 0) {
                count--;
                while (count == 0) {
                    if (end - start < minLen) {
                        minLen = end - start;
                        minStart = start;
                    }
                    if (exist[s[start]]++ == 0) {
                        count++;
                    }
                    start++;
                }
            }
        }
        return minLen > s.length() ? "" : s.substr(minStart, minLen);
    }
};
**/
