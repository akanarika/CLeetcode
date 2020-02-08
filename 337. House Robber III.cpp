/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
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
    int rob(TreeNode* root) {
        vector<int> res = robnode(root);
        return max(res[0], res[1]);
    }

private:
    vector<int> robnode(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }

        vector<int> left = robnode(root->left);
        vector<int> right = robnode(root->right);

        vector<int> res = {
            max(left[0], left[1]) + max(right[0], right[1]),
            left[0] + right[0] + root->val
        };

        return res;
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
/*
class Solution {
public:
    int rob(TreeNode* root) {
        if (!root) return 0;
        int exclude = 0;
        int robroot = rob(root, exclude);
        return max(robroot, exclude);
    }

    int rob(TreeNode* root, int& exclude) {
        if (!root->left && !root->right) {
            exclude = 0;
            return root->val;
        }
        int left = 0;
        int right = 0;
        int lexclude = 0;
        int rexclude = 0;
        if (root->left) left = rob(root->left, lexclude);
        if (root->right) right = rob(root->right, rexclude);
        exclude = max(left, lexclude) + max(right, rexclude);
        return lexclude + rexclude + root->val;
    }
};
*/

