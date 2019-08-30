class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if (A.empty()) return 0;

        int count = 0;
        for (int i = 0; i < A[0].length(); i++) {
            for (int j = 1; j < A.size(); j++) {
                if (A[j - 1][i] > A[j][i]) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};
