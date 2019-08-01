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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        int val = 0;
        if (root && root->left && !root->left->left && !root->left->right) {
            val = root->left->val;
        }
        return val + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
