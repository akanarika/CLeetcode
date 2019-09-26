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
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int num = 0;
        return sumNumbers(root, num); 
    }
    
    int sumNumbers(TreeNode* node, int num) {
        num = num * 10 + node->val;
        if (!node->left && !node->right) return num;
        int left = 0;
        int right = 0;
        if (node->left) left = sumNumbers(node->left, num);
        if (node->right) right = sumNumbers(node->right, num);
        return left + right;
    }
};
