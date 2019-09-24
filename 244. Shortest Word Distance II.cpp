class WordDistance {
    unordered_map<string, vector<int>> m;
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            m[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int res = INT_MAX;
        for (auto i1 : m[word1]) {
            for (auto i2 : m[word2]) {
                res = min(res, i1 > i2 ? (i1 - i2) : (i2 - i1));
            }
        }
        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
