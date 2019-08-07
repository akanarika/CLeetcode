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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        queue<TreeNode*> q;
        q.push(root);
        int res = -1;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            for (auto child : {node->left, node->right}) {
                if (!child) continue;
                if (child->val == root->val) q.push(child);
                else {
                    if (res == -1) res = child->val;
                    else res = min(child->val, res);
                }
            }
        }
        return res; 
    }
};
