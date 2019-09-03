class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int p = 0;
        int q = 0;
        int count = 0;
        while ((p < g.size()) && (q < s.size())) {
            if (g[p] <= s[q]) {
                count++;
                p++;
            }
            q++;
        }
        return count;
    }
};
