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
    int rob(TreeNode* root) {
        if (!root) return 0;
        int exclude = 0;
        int robroot = rob(root, exclude);
        return max(robroot, exclude);
    }

    int rob(TreeNode* root, int& exclude) {
        if (!root->left && !root->right) {
            exclude = 0;
            return root->val;
        }
        int left = 0;
        int right = 0;
        int lexclude = 0;
        int rexclude = 0;
        if (root->left) left = rob(root->left, lexclude);
        if (root->right) right = rob(root->right, rexclude);
        exclude = max(left, lexclude) + max(right, rexclude);
        return lexclude + rexclude + root->val;
    }
};
