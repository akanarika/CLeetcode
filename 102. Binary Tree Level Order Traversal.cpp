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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> level;
        level.push(root);
        level.push(NULL);
        vector<vector<int>> res;
        vector<int> vals;
        if (root == NULL) return res;
        
        while (!level.empty()) {
            TreeNode* curr = level.front();
            level.pop();
            if (curr == NULL) {
                if (!level.empty()) level.push(NULL);
                res.push_back(vals);
                vals.clear();
            } else {
                vals.push_back(curr->val);
                if(curr->left) level.push(curr->left);
                if(curr->right) level.push(curr->right);
            }
        }
        return res;
    }
};