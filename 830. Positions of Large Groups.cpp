class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        if (S.empty() || S.length() <= 2) return {};

        vector<vector<int>> res;
        int p, q;
        p = q = 0;

        while (q < S.length()) {
            q++;
            while (S[p] == S[q] && q < S.length()) {
                q++;
            }
            if (q - p >= 3) res.push_back({p, q - 1});
            p = q;
        }
        return res; 
    }
};
