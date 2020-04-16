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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        
        vector<int> res;
        vector<TreeNode*> level = {root};
        while (!level.empty()) {
            res.push_back(level.back()->val);
            vector<TreeNode*> nlevel;
            for (const auto& node : level) {
                if (node->left) nlevel.push_back(node->left);
                if (node->right) nlevel.push_back(node->right);
            }
            level = nlevel;
        }
        return res;
    }
};
