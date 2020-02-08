/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, set<int>>> m;
        pre(root, 0, 0, m);
        vector<vector<int>> v;
        for (auto xs : m) {
            vector<int> l;
            for (auto ys : xs.second) {
                for (auto e : ys.second) {
                    l.push_back(e);
                }
            }
            v.push_back(l);
        }
        return v;
    }

    void pre(TreeNode* node, int x, int y, map<int, map<int, set<int>>>& m) {
        if (!node) return;
        m[x][y].insert(node->val);
        if (node->left) {
            pre(node->left, x - 1, y + 1, m);
        }
        if (node->right) {
            pre(node->right, x + 1, y + 1, m);
        }
    }
};
// @lc code=end
