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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == NULL) return res;
        
        unordered_map<TreeNode*, string> path;
        path[root] = to_string(root->val);
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            if (node->left == NULL && node->right == NULL) {
                res.push_back(path[node]);
            } else {
                if (node->left != NULL) {
                    path[node->left] = path[node] + "->" + to_string(node->left->val);
                    s.push(node->left);
                }
                if (node->right != NULL) {
                    path[node->right] = path[node] + "->" + to_string(node->right->val);
                    s.push(node->right);
                }
            }
        }
        
        return res;
    }
};