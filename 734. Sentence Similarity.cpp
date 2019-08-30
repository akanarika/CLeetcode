class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) return false;
        int n = words1.size();

        for (int i = 0; i < n; i++) {
            if (words1[i] == words2[i]) continue;
            vector<string> pair = {words1[i], words2[i]};
            if (find(pairs.begin(), pairs.end(), pair) == pairs.end()) {
                vector<string> pair = {words2[i], words1[i]};
                if (find(pairs.begin(), pairs.end(), pair) == pairs.end()) {
                    return false;
                }
            }
        }

        return true;
    }
};
