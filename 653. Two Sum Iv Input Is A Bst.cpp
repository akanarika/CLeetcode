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
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        queue<TreeNode*> q;
        unordered_set<int> s;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (s.find(node->val) != s.end()) {
                return true;
            } else {
                s.insert(k - node->val);
            }
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return false;
    }
};
