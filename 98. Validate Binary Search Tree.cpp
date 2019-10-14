/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        pair<int, int> mm;
        return minMax(root, mm);
    }

    bool minMax(TreeNode* node, pair<int, int>& mm) {
        pair<int, int> l;
        pair<int, int> r;
        bool lv = true;
        bool rv = true;
        if (node->left) {
            lv = minMax(node->left, l);
        }
        if (node->right) {
            rv = minMax(node->right, r);
        }

        if (lv && rv && (!node->left || l.second < node->val) && (!node->right || r.first > node->val)) {
            mm = make_pair(node->left ? l.first : node->val, node->right ? r.second : node->val);
            return true;
        }

        return false;
    }
};
// @lc code=end
