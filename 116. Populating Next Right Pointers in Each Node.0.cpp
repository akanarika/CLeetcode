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
        if (!root) return root;

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            queue<Node*> nq;
            Node* lastNode = NULL;
            Node* node = NULL;
            while (!q.empty()) {
                node = q.front();
                if (lastNode) lastNode->next = node;
                if (node->left) nq.push(node->left);
                if (node->right) nq.push(node->right);
                lastNode = node;
                q.pop();
            }
            q = nq;
        }
        return root;
    }
};
