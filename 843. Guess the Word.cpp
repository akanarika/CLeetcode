/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
private:
    string getword(vector<string>& wordlist) {
        int minscore = INT_MAX;
        string word = "";
        for (const auto& w : wordlist) {
            int score = 0;
            for (const auto& m : wordlist) {
                score += (match(m, w) == 0);
            }
            if (score <= minscore) {
                minscore = score;
                word = w;
            }
        }
        return word;
    }
    
    int match(string w, string m) {
        int score = 0;
        for (int i = 0; i < 6; i++) {
            if (m[i] == w[i]) score++;
        }
        return score;
    }
    
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for (int i = 0; i < 10; i++) {
            string w = getword(wordlist);
            int score = master.guess(w);
            vector<string> newlist;
            for (const auto& word : wordlist) {
                if (w != word && match(w, word) == score) {
                    newlist.push_back(word);
                }
            }
            wordlist = newlist;
        }
    }
};
