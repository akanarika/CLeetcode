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
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int left_height = 0;
        int right_height = 0;
        TreeNode* left_node = root;
        TreeNode* right_node = root;
        while (left_node != NULL) {
            left_height++;
            left_node = left_node->left;
        }
        while (right_node != NULL) {
            right_height++;
            right_node = right_node->right;
        }
        if (left_height == right_height) return (1 << left_height) - 1;
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
};