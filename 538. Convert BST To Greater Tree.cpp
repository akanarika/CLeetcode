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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        return convertBST(root, sum);
    }

    TreeNode* convertBST(TreeNode* root, int& sum) {
        if (!root) return NULL;
        if (root->right) convertBST(root->right, sum);
        sum += root->val;
        root->val = sum;
        if (root->left) convertBST(root->left, sum);
        return root;
    }

};
