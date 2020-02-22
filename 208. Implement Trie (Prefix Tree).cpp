/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class Trie {
private:
    struct Node {
        char c;
        bool isEnd;
        unordered_map<char, Node*> children;

        Node(char _c) : c(_c), isEnd(false) {};
        Node(char _c, bool _isEnd) : c(_c), isEnd(_isEnd) {};
    };

    Node* root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node('0', false);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (!(curr->children).count(c)) curr->children[c] = new Node(c);
            curr = curr->children[c];
            if (!curr->isEnd) curr->isEnd = (i == word.size() - 1);
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (!(curr->children).count(c)) return false;
            curr = curr->children[c];
            if (i == word.size() - 1) return curr->isEnd;
        }
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* curr = root;
        for (int i = 0; i < prefix.size(); i++) {
            char c = prefix[i];
            if (!curr->children.count(c)) return false;
            curr = curr->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
/**
class Trie {
    class Node {
    public:
        vector<Node *> children;
        bool isEnd;
        Node () {
            children = vector<Node *>(26);
            isEnd = false;
        }
    };
    Node* root;
public:
    // Initialize your data structure here. 
    Trie() {
        root = new Node();
    }
    
    // Inserts a word into the trie. 
    void insert(string word) {
        Node* currNode = root;
        for (auto it = word.begin(); it != word.end(); it++) {
            char c = *it;
            if (!currNode->children[c - 'a']) {
                currNode->children[c - 'a'] = new Node();
            }
            if (!currNode->children[c - 'a']->isEnd && (it == prev(word.end()))) {
                currNode->children[c - 'a']->isEnd = true;
            }
            currNode = currNode->children[c - 'a'];
        }
    }
    
    // Returns if the word is in the trie. 
    bool search(string word) {
        Node* currNode = root;
        for (auto it = word.begin(); it != word.end(); it++) {
            char c = *it;
            if (!currNode->children[c - 'a']) {
                return false;
            }
            if (it == prev(word.end())) {
                return currNode->children[c - 'a']->isEnd;
            }
            currNode = currNode->children[c - 'a'];
        }
        return true;
    }
    
    // Returns if there is any word in the trie that starts with the given prefix.
    bool startsWith(string prefix) {
        Node* currNode = root;
        for (auto it = prefix.begin(); it != prefix.end(); it++) {
            char c = *it;
            if (!currNode || !currNode->children[c - 'a']) {
                return false;
            }
            currNode = currNode->children[c - 'a'];
        }
        return true;
    }
};
**/

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

