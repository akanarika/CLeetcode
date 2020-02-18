/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (key == root->val) {
            if (!root->right) return root->left;
            TreeNode* prev = root;
            TreeNode* min = root->right;
            while (min->left) {
                prev = min;
                min = min->left;
            }
            root->val = min->val;
            if (min == prev->left) prev->left = deleteNode(min, min->val);
            else prev->right = deleteNode(min, min->val);
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};
// @lc code=end

/**
 *
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val == key) {
            if (!root->right) root = root->left;
            else {
                TreeNode* node = root;
                TreeNode* right = root->right;
                while (right->left) {
                    node = right;
                    right = right->left;
                }
                root->val = right->val;
                if (node != root) node->left = node->left->right;
                else node->right = node->right->right;
            }
            return root;
        } else {
            if (key > root->val) root->right = deleteNode(root->right, key);
            else root->left = deleteNode(root->left, key);
            return root;
        }
    }
};

**/
