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
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return 0;
        int count = 0;
        int val = 0;
        countNode(root, count, k, val);
        return val;
    }

    bool countNode(TreeNode* node, int& count, int k, int& val) {
        if (node->left && countNode(node->left, count, k, val)) {
            return true;
        }
        if ((++count) == k) {
            val = node->val;
            return true;
        }
        if (node->right && countNode(node->right, count, k, val)) {
            return true;
        }
        return false;
    }
};
