class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int N = words.size();
        unordered_map<string, int> idx;
        for (int i = 0; i < N; i++) {
            idx[words[i]] = i;
        }
        
        vector<vector<int>> res;
        for (int i = 0; i < N; i++) {
            string w = words[i];
            for (int j = 0; j <= w.length(); j++) {
                if (isPal(w, 0, j - 1)) {
                    string sub = w.substr(j, w.length() - j);
                    reverse(sub.begin(), sub.end());
                    if (idx.count(sub) && idx[sub] != i) res.push_back({idx[sub], i});
                }
                if (j > 0 && isPal(w, w.length() - j, w.length() - 1)) {
                    string sub = w.substr(0, w.length() - j);
                    reverse(sub.begin(), sub.end());
                    if (idx.count(sub) && idx[sub] != i) res.push_back({i, idx[sub]});
                }
                
            }
        }
        return res;
    }
private:
    bool isPal(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};