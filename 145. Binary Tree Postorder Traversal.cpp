/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        stack<TreeNode*> stk;
        unordered_map<TreeNode*, int> solved;
        vector<int> v;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            if (solved[node] == ((node->left ? 1 : 0) + (node->right ? 1 : 0))) {
                v.push_back(node->val);
                stk.pop();
                continue;
            }
            if (node->right) {
                stk.push(node->right);
                solved[node]++;
            }
            if (node->left) {
                stk.push(node->left);
                solved[node]++;
            }
        }
        return v;
    }
};

/**
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return v;
    }

private:
    vector<int> v;
    void postorder(TreeNode* root) {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        v.push_back(root->val);
    }
};
**/
// @lc code=end
