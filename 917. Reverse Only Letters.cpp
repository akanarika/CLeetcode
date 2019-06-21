class Solution {
public:
    string reverseOnlyLetters(string S) {
        if (S.empty()) {
            return S;
        }
        
        int p1 = 0;
        int p2 = S.length() - 1;
        while (p1 < p2) {
            if (isalpha(S[p1]) && isalpha(S[p2])) {
                char tmp = S[p1];
                S[p1] = S[p2];
                S[p2] = tmp;
                p1++;
                p2--;
            } else {
                if (!isalpha(S[p1])) {
                    p1++;
                }
                if (!isalpha(S[p2])) {
                    p2--;
                }
            }
        }
        return S;
    }
};