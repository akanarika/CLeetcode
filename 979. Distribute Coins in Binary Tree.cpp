/*
 * @lc app=leetcode id=979 lang=cpp
 *
 * [979] Distribute Coins in Binary Tree
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
    int distributeCoins(TreeNode* root) {
        per(root);
        return move + root->val - 1;
    }

private:
    int move = 0;
    int per(TreeNode* root) {
        if (!root) return 0; // don't need move
        if (!root->left && !root->right) {
            if (root->val <= 1) return root->val - 1; // need some or 0
            move += root->val - 1;
            return root->val - 1; // gave some
        }
        int left = per(root->left);
        int right = per(root->right);
        root->val += left + right;
        move -= (left < 0 ? left : 0) + (right < 0 ? right : 0);

        if (root->val <= 1) return root->val - 1;
        move += root->val - 1;
        return root->val - 1;
    }
};
// @lc code=end
