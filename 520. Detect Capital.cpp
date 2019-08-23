class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.length() < 2) return true;

        char c = word[0];
        if (c >= (int)('a') && c <= (int)('z')) {
            for (int i = 1; i < word.length(); i++) {
                c = word[i];
                if (!(c >= (int)('a') && c <= (int)('z'))) {
                    return false;
                }
            }
        } else if (c >= 'A' && c <= 'Z') {
            c = word[1];
            if (c >= 'A' && c <= 'Z') {
                for (int i = 2; i < word.length(); i++) {
                    c = word[i];
                    if (!(c >= 'A' && c <= 'Z')) {
                        return false;
                    }
                }
            } else {
                for (int i = 2; i < word.length(); i++) {
                    c = word[i];
                    if (!(c >= 'a' && c <= 'z')) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
