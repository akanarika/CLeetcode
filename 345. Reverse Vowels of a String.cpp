class Solution {
public:
    string reverseVowels(string s) {
        int p1 = 0;
        int p2 = s.size() - 1;
        while (p1 < p2) {
            while (!isVowel(s[p1]) && p1 < s.size()) {
                p1++;
            }
            while (!isVowel(s[p2]) && p2 >= 0) {
                p2--;
            }
            if (p1 >= p2) break;
            char tmp = s[p1];
            s[p1] = s[p2];
            s[p2] = tmp;
            p1++;
            p2--;
        }
        return s;
    }
private:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
               || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
};