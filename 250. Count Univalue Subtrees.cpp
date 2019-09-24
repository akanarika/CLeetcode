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
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        isUnivalSubtree(root, count);
        return count;
    }

    bool isUnivalSubtree(TreeNode* node, int& count) {
        if (!node) return true;
        if (!node->left && !node->right) {
            count++;
            return true;
        }

        bool left = false;
        if (isUnivalSubtree(node->left, count) && (!node->left || node->left->val == node->val)) {
            left = true;
        }

        bool right = false; 
        if (isUnivalSubtree(node->right, count) && (!node->right || node->right->val == node->val)) {
            right = true;
        }

        if (left && right) {
            count++;
            return true;
        }

        return false;
    }
};
