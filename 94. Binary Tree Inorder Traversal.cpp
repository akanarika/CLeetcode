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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        unordered_map<TreeNode*, bool> visited;
        stack<TreeNode*> s;
        s.push(root);
        vector<int> res;
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            if (visited[node]) res.push_back(node->val);
            else {
                if (node->right) s.push(node->right);
                s.push(node);
                if (node->left) s.push(node->left);
                visited[node] = true;
            }
        }
        return res;
    }
};
