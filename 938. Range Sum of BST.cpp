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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        rangeSumBST(root, L, R, sum);
        return sum;
    }
    
    void rangeSumBST(TreeNode* root, int L, int R, int& sum) {
        if (!root) return;
        rangeSumBST(root->left, L, R, sum);
        if ((root->val <= R) && (root->val >= L)) {
            sum += root->val;
        }
        rangeSumBST(root->right, L, R, sum);
    }
};