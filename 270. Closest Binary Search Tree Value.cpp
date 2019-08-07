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
    int closestValue(TreeNode* root, double target) {
        if (target == root->val) return target;
        TreeNode* node = (target > root->val) ? (root->right) : (root->left);
        if (node) {
            int closestNext = closestValue(node, target);
            double currNext = abs(target - closestNext);
            double currDiff = abs(target - root->val);
            return (currDiff < currNext) ? (root->val) : closestNext;
        } else {
            return root->val;
        }
    }
};
