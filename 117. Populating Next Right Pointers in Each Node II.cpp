/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        vector<Node*> level = {root};
        while (!level.empty()) {
            vector<Node*> newLevel;
            Node* last = NULL;
            for (const auto& node : level) {
                if (last) last->next = node;
                last = node;
                if (node->left) newLevel.push_back(node->left);
                if (node->right) newLevel.push_back(node->right);
            }
            level = newLevel;
        }
        return root;
    }
};
