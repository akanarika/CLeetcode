/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        TreeLinkNode* last = NULL;
        queue<TreeLinkNode*> s;
        s.push(root);
        s.push(NULL);
        while (!s.empty()) {
            TreeLinkNode* u = s.front();
            s.pop();
            if (last != NULL) last->next = u;
            last = u;
            if (u != NULL) {
                if (u->left != NULL) s.push(u->left);
                if (u->right != NULL) s.push(u->right);
            } else {
                if (!s.empty()) s.push(NULL);
            }
        }
    }
};