class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;

        for (int i = 1; i < A.size(); i++) {
            A[i - 1] = A[i] - A[i - 1];
        }

        int res = 0;
        int curr = 1;
        for(int i = 1; i < A.size() - 1; i++) {
            if (A[i] == A[i - 1]) {
                curr++;
            } 
            
            if ((A[i] != A[i - 1]) || (i == A.size() - 2)) {
                if (curr >= 2) {
                    res += ((curr - 1) + 1) * (curr - 1) / 2;
                }
                curr = 1;
            }
        }

        return res;
    }
};
