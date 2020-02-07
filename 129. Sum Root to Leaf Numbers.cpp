/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) {
            return root->val;
        }
        if (root->left) {
            root->left->val += root->val * 10;
        }
        if (root->right) {
            root->right->val += root->val * 10;
        }
        return sumNumbers(root->left) + sumNumbers(root->right);
    }
};
// @lc code=end

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
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
**/
