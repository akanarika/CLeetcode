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
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;
        queue<TreeNode*> level;
        level.push(root);
        queue<TreeNode*> nlevel;
        int i = 0;
        int ix = -1;
        int iy = -1;
        while (!level.empty()) {
            TreeNode* node = level.front();
            level.pop();
            if (node && (node->left || node->right)) {
                nlevel.push(node->left);
                nlevel.push(node->right);
                if (node->left) {
                    if (node->left->val == x) ix = i;
                    if (node->left->val == y) iy = i;
                }
                i++;
                if (node->right) {
                    if (node->right->val == x) ix = i;
                    if (node->right->val == y) iy = i;
                }
                i++;
            }
            if (level.empty()) {
                if (ix != -1 && iy != -1) {
                    if (ix == iy + 1) return iy % 2 != 0;
                    if (ix == iy - 1) return ix % 2 != 0;
                    return true;
                } else if (ix != -1 || iy != -1) return false;
                else {
                    i = 0;
                    swap(level, nlevel);
                }
            }
        }
        return false;
    }
};
