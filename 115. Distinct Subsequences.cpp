class Solution {
public:
    int numDistinct(string s, string t) {
        int ns = s.size();
        int nt = t.size();
        vector<vector<int>> opt;
        for (int i = 0; i <= nt; i++) {
            vector<int> line(ns + 1, 0);
            opt.push_back(line);
        }
        for (int i = 0; i <= ns; i++) {
            opt[0][i] = 1;
        }
        for (int i = 1; i <= nt; i++) {
            opt[i][0] = 0;
        }
        for (int i = 1; i <= nt; i++) {
            for (int j = 1; j <= ns; j++) {
                if (t[i-1] == s[j-1]) {
                    opt[i][j] = opt[i-1][j-1] + opt[i][j-1];
                } else {
                    opt[i][j] = opt[i][j-1];
                }
            }
        }
        return opt[nt][ns];
    }
};