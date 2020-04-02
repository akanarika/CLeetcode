class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int ha = A.size();
        int wa = A[0].size();
        int wb = B[0].size();
        vector<vector<int>> C(ha, vector<int>(wb, 0));
        for (int ra = 0; ra < ha; ra++) {
            for (int cb = 0; cb < wb; cb++) {
                for (int ca = 0; ca < wa; ca++) C[ra][cb] += A[ra][ca] * B[ca][cb];
            }
        }
        return C;
    }
};
