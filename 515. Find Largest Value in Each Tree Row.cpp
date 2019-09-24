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
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        res.push_back(root->val);
        while (!q.empty()) {
            int m = INT_MIN;
            queue<TreeNode*> nq;
            while (!q.empty()) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    nq.push(node->left);
                    m = max(m, node->left->val);
                }
                if (node->right) {
                    nq.push(node->right);
                    m = max(m, node->right->val);
                }
            }
            if (!nq.empty()) res.push_back(m);
            swap(q, nq);
        }
        return res; 
    }
};
