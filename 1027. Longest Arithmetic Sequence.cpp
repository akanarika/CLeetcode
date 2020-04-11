class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        unordered_map<int, unordered_map<int, int>> m;
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                int diff = A[i] - A[j];
                int last = m[j].count(diff) ? m[j][diff] : 1;
                m[i][diff] = max(m[i][diff], last + 1);
                res = max(res, m[i][diff]);
            }
        }
        return res;
    }
};
