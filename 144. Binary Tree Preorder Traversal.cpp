/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        preorder(root, v);
        return v;
    }

private:
    void preorder(TreeNode* root, vector<int>& v) {
        if (!root) return;
        v.push_back(root->val);
        preorder(root->left, v);
        preorder(root->right, v);
    }
};
// @lc code=end
