class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.empty() || B.empty()) return false;
        if (A.length() != B.length()) return false;

        int a = 0;
        int b = 0;
        vector<int> count(256, 0);
        bool hasDup = false;
        for (int i = 0; i < A.length(); i++) {
            if (A[i] - B[i]) {
                if (a == 0) a = A[i] - B[i];
                else if (b == 0) b = A[i] - B[i];
                else return false;
            }
            count[A[i]]++;
            if (count[A[i]] > 1) hasDup = true;
        }

        return (a == 0 && b == 0 && hasDup) || (a != 0 && b != 0 && a + b == 0);
    }
};
