/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> res;
        res.push_back({root->val});
        while (!q.empty()) {
            queue<Node*> child;
            vector<int> level;
            while (!q.empty()) {
                Node* node = q.front();
                q.pop();
                for (const auto& c : node->children) {
                    level.push_back(c->val);
                    child.push(c);
                }
            }
            if (!level.empty()) res.push_back(level);
            swap(q, child);
        }
        return res;
    }
};
