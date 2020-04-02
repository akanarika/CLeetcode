/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return root;
        auto pr = build(root);
        pr.first->left = pr.second;
        pr.second->right = pr.first;
        return pr.first;
    }
    
private:
    pair<Node*, Node*> build(Node* root) {
        if (!root) return make_pair(root, root);
        Node* node = root;
        Node* head = node;
        Node* tail = node;
        if (root && root->left) {
            auto lp = build(root->left);
            node->left = lp.second;
            lp.second->right = node;
            head = lp.first;
        }
        if (root && root->right) {
            auto rp = build(root->right);
            node->right = rp.first;
            rp.first->left = node;
            tail = rp.second;
        }
        return make_pair(head, tail);
    }
};
