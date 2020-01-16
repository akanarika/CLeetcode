/*
 * @lc app=leetcode id=1110 lang=cpp
 *
 * [1110] Delete Nodes And Return Forest
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (!root) return {};
        vector<TreeNode*> res;
        unordered_set<int> to_del;
        for (auto del : to_delete) {
            to_del.insert(del);
        }

        stack<TreeNode*> tree;
        stack<TreeNode*> trees;
        trees.push(root);
        while (!trees.empty()) {
            TreeNode* currTree = trees.top();
            trees.pop();
            if (to_del.find(currTree->val) != to_del.end()) {
                if (currTree->left) trees.push(currTree->left);
                if (currTree->right) trees.push(currTree->right);
            } else {
                res.push_back(currTree);
                tree.push(currTree);
                while (!tree.empty()) {
                    TreeNode* curr = tree.top();
                    tree.pop();
                    if (to_del.find(curr->val) != to_del.end()) {
                        if (curr->left) trees.push(curr->left);
                        if (curr->right) trees.push(curr->right);
                    } else {
                        if (curr->left) tree.push(curr->left);
                        if (curr->right) tree.push(curr->right);
                    }
                    if (curr->left && to_del.find(curr->left->val) != to_del.end()) {
                        curr->left = NULL;
                    }
                    if (curr->right && to_del.find(curr->right->val) != to_del.end()) {
                        curr->right = NULL;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
