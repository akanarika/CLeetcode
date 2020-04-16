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
private:
    bool dfs(TreeNode* node, vector<int>& voyage, int& i, vector<int>& res) {
        if (!node) return true;
        if (node->val != voyage[i++]) return false;
        if (!node->left && !node->right) return true;
        if (node->right && node->right->val == voyage[i]) {
            if (node->left) res.push_back(node->val);
            return dfs(node->right, voyage, i, res) && dfs(node->left, voyage, i, res);
        }
        return dfs(node->left, voyage, i, res) && dfs(node->right, voyage, i, res);
    }
    
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> res;
        int i = 0;
        if (dfs(root, voyage, i, res)) return res;
        else return {-1};
    }
};
