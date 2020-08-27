class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> strcnt;
        vector<int> cnt(26, 0);
        int curr = 0;
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (cnt[s[i] - 'a']++ == 0) curr++;
            if ((i >= minSize) && (cnt[s[i - minSize] - 'a']-- == 1)) curr--;
            if (i >= minSize - 1 && curr <= maxLetters) {
                const string sub = s.substr(i + 1 - minSize, minSize);
                strcnt[sub]++;
                res = max(res, strcnt[sub]);
            }
        }
        
        return res;
    }
};
