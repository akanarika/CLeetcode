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
    int minCameraCover(TreeNode* root) {
        res = 0;
        if (cover(root) == 0) res++;
        return res;
    }
    
private:
    int res;
    int cover(TreeNode* root) {
        if (!root) return 1;
        int l = cover(root->left);
        int r = cover(root->right);
        if (l == 0 || r == 0) {
            res++;
            return 2;
        }
        if (l == 2 || r == 2) {
            return 1;
        }
        return 0;
    }
};