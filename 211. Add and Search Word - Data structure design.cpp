class WordDictionary {
private:
    class Node {
    public:
        char c;
        bool isEnd = false;
        unordered_map<char, Node*> children;
        Node(char _c) : c(_c) {}
    };
    Node* root;
    bool search(string word, Node* root) {
        if (word.empty()) return root->isEnd;
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                for (const auto& pr : node->children) {
                    if (search(word.substr(i + 1), pr.second)) return true;
                }
                return false;
            }
            if (!node->children.count(c)) {
                return false;
            }
            if (i == word.size() - 1) {
                return node->children[c]->isEnd;
            }
            node = node->children[c];
        }
        return false;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node(' ');
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) { 
            char c = word[i];
            if (!node->children.count(c)) {
                Node* cnode = new Node(c);
                if (i == word.size() - 1) cnode->isEnd = true;
                else cnode->isEnd = false;
                node->children[c] = cnode;
            } else if (i == word.size() - 1) {
                node->children[c]->isEnd = true;
            }
            node = node->children[c];
        }
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, root);
    }
        
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
 