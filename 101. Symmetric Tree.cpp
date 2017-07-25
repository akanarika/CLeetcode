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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return isFlip(root->left, root->right);
    }
private:
    bool isFlip(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) {
            return p == NULL && q == NULL;
        }
        return isFlip(p->left, q->right) && isFlip(p->right, q->left) && p->val == q->val;
    }
};