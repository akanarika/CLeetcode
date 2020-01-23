/*
 * @lc app=leetcode id=897 lang=cpp
 *
 * [897] Increasing Order Search Tree
 */

// @lc code=start
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
    TreeNode* curr;
    TreeNode* newRoot;
public:
    TreeNode* increasingBST(TreeNode* root) {
        newRoot = new TreeNode(0);
        curr = newRoot;
        visit(root);
        return newRoot->right;
    }

    void visit(TreeNode* root) {
        if (!root) return;
        visit(root->left);
        root->left = NULL;
        curr->right = root;
        curr = curr->right;
        visit(root->right);
    }
};
// @lc code=end
