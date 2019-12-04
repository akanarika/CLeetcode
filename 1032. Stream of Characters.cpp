/*
 * @lc app=leetcode id=1032 lang=cpp
 *
 * [1032] Stream of Characters
 */

// @lc code=start
class Trie {
public:
    bool isEnd;
    unordered_map<char, Trie *> nodes;

    Trie() {
        isEnd = false;
    }
    
    void insert(string word) {
        Trie* curr = this;
        for (auto it = word.begin(); it != word.end(); it++) {
            if (curr->nodes.find(*it) == curr->nodes.end()) {
                curr->nodes[*it] = new Trie();
            }
            if (next(it) == word.end()) {
                curr->nodes[*it]->isEnd = true;
            }
            curr = curr->nodes[*it];
        }
    }

    bool search(string word) {
        Trie* curr = this;
        for (auto it = word.begin(); it != word.end(); it++) {
            if (curr->nodes.find(*it) == curr->nodes.end()) {
                return false;
            } else {
                if (curr->nodes[*it]->isEnd) return true;
            }
            if (next(it) == word.end()) {
                return curr->nodes[*it]->isEnd;
            }
            curr = curr->nodes[*it];
        }
        return true;
    }
};

class StreamChecker {
private:
    unordered_set<string> dict;
    Trie t;
    size_t wordLen;
    string currStr;
public:
    StreamChecker(vector<string>& words) {
        wordLen = 0;
        currStr = "";
        for (auto w : words) {
            reverse(w.begin(), w.end());
            t.insert(w);
            wordLen = max(wordLen, w.length());
        }
    }
    
    bool query(char letter) {
        currStr = letter + currStr;
        if (currStr.length() > wordLen) currStr.pop_back();
        return t.search(currStr);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
// @lc code=end
