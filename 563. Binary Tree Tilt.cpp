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
    int findTilt(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return 0;
        int sum = findTilt(root->left) + findTilt(root->right) + abs((root->left?root->left->val:0) - (root->right?root->right->val:0));
        root->val += (root->left?root->left->val:0) + (root->right?root->right->val:0);
        return sum;
    }
};
