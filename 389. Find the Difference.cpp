class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for (auto c : (s + t)) {
            res ^= c;
        }
        return res;
    }
};
