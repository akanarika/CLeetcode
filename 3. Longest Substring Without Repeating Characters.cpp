class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int i = 0;
        unordered_map<char, int> last;
        for (int j = 0; j < s.length(); j++) {
            if ((last.find(s[j]) != last.end()) && (last[s[j]] >= i)) {
                i = last[s[j]] + 1;
            } else {
                maxLen = max(j - i + 1, maxLen);
            }
            last[s[j]] = j;
        }
        return maxLen;
    }
};

/**
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();
        unordered_set<char> char_set;
        int len = 0;
        int p1 = 0;
        int p2 = 0;
        while (p2 < s.size()) {
            while (char_set.find(s[p2]) != char_set.end()) {
                char_set.erase(s[p1]);
                p1++;
            }
            char_set.insert(s[p2]);
            len = max(p2 - p1 + 1, len);
            p2++;
        }
        return len;
    }
};
**/

