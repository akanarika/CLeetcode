class Solution {
    class Node {
    public:
        bool isEnd;
        unordered_map<char, Node*> children;
        Node () : isEnd(false) {}
    };
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = new Node();
        Node* curr = root;
        for (const auto& w : words) {
            curr = root;
            for (auto it = w.begin(); it != w.end(); it++) {
                char c = *it;
                if (curr->children.count(c)) {
                    if (next(it) == w.end()) curr->children[c]->isEnd = true;
                } else {
                    Node* node = new Node();
                    curr->children[c] = node;
                    if (next(it) == w.end()) curr->children[c]->isEnd = true;
                }
                curr = curr->children[c];
            }
        }
        
        unordered_set<string> res;
        string word;
        int h = board.size();
        int w = board[0].size();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                unordered_set<string> seen;
                dfs(i, j, root, board, res, seen, word);
            }
        }
        return vector<string>(res.begin(), res.end());
    }
    
    void dfs(int i, int j, Node* node, vector<vector<char>>& board, unordered_set<string>& res, unordered_set<string>& seen, string& curr) {
        if (i < 0 || i >= board.size()) return;
        if (j < 0 || j >= board[0].size()) return;
        if (seen.count(to_string(i) + " " + to_string(j))) return;
        if (!node->children.count(board[i][j])) return;
        
        Node* child = node->children[board[i][j]];
        seen.insert(to_string(i) + " " + to_string(j));
        curr.push_back(board[i][j]);
        if (child->isEnd) res.insert(curr);
        dfs(i - 1, j, child, board, res, seen, curr);
        dfs(i + 1, j, child, board, res, seen, curr);
        dfs(i, j - 1, child, board, res, seen, curr);
        dfs(i, j + 1, child, board, res, seen, curr);
        seen.erase(to_string(i) + " " + to_string(j));
        curr.pop_back();
    }
    
};