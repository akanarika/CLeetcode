class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int p = 1;
        string a = A;
        while (A.length() < B.length() + 2 * a.length()) {
            if (A.find(B) == string::npos) {
                A += a;
                p++;
            } else {
                return p;
            }
        }
        return -1;
    }
};
