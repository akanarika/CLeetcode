/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        queue<TreeNode*> q;
        unordered_map<TreeNode*, int> paths;
        q.push(root);
        paths[root] = root->val;
        while (!q.empty()) {
            TreeNode* u = q.front();
            q.pop();
            if (u->left == NULL && u->right == NULL && paths[u] == sum) return true;
            if (u->left != NULL) {
                paths[u->left] = paths[u] + u->left->val;
                q.push(u->left);
            }
            if (u->right != NULL) {
                paths[u->right] = paths[u] + u->right->val;
                q.push(u->right);
            }
        }
        return false;
    }
};