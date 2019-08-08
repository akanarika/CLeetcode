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
    int longest = 0;
public:
    int longestUnivaluePath(TreeNode* root) {
        longerUnivaluePath(root);
        return longest;
    }
    
    int longerUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 0;
        int longer = 0;
        int llonger = longerUnivaluePath(root->left);
        int rlonger = longerUnivaluePath(root->right);
        if (root->left && root->val == root->left->val) {
            longer = 1 + llonger;
            longest = max(longest, longer);
        }
        if (root->right && root->val == root->right->val) {
            longest = max(longest, longer + 1 + rlonger);
            longer = max(longer, 1 + rlonger);
        }
        longest = max(longest, longer);
        return longer;
    }
};