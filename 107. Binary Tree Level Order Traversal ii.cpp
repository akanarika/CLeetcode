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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> res;
        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);
        queue<TreeNode*> nq;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) nq.push(node->left);
            if (node->right) nq.push(node->right);
            level.push_back(node->val);
            if (q.empty()) {
                swap(q, nq);
                res.insert(res.begin(), level);
                level.clear();
            }
        }
        return res;
    }
};
