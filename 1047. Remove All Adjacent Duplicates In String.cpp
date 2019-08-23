class Solution {
public:
    string removeDuplicates(string S) {
        if (S.empty()) return S;

        int p = 0;
        while (p < S.length()) {
            if (S[p + 1] == S[p]) {
                S = S.substr(0, p) + S.substr(p + 2);
                if (p > 0) p = p - 1;
                else p = 0;
            } else {
                p++;
            }
        }

        return S;
    }
};
