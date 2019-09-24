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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val == key) {
            if (!root->right) root = root->left;
            else {
                TreeNode* node = root;
                TreeNode* right = root->right;
                while (right->left) {
                    node = right;
                    right = right->left;
                }
                root->val = right->val;
                if (node != root) node->left = node->left->right;
                else node->right = node->right->right;
            }
            return root;
        } else {
            if (key > root->val) root->right = deleteNode(root->right, key);
            else root->left = deleteNode(root->left, key);
            return root;
        }
    }
};
