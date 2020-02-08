/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return {};
        vector<int> curr;
        path(root, sum, curr);
        return res;
    }

private:
    vector<vector<int>> res;
    void path(TreeNode* node, int sum, vector<int>& curr) {
        curr.push_back(node->val);

        if (!node->left && !node->right) {
            if (sum == node->val) {
                res.push_back(curr);
            }
        } else {
            if (node->left) {
                path(node->left, sum - node->val, curr);
            }
            if (node->right) {
                path(node->right, sum - node->val, curr);
            }
        }

        curr.pop_back();
    }
};
// @lc code=end
