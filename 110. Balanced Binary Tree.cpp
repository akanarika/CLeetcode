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
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != INT_MAX;
    }
    
    int checkHeight(TreeNode* node) {
        if (node == NULL) return -1;
        int left_height = checkHeight(node->left);
        int right_height = checkHeight(node->right);
        if (left_height == INT_MAX || right_height == INT_MAX) return INT_MAX;
        int diff = abs(left_height - right_height);
        if (diff <= 1) return max(left_height, right_height) + 1;
        return INT_MAX;
    }
};