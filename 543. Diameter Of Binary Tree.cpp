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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int max = INT_MIN;
        depthOfNode(root, max); 
        return max;
    }

    int depthOfNode(TreeNode* node, int& maxInt) {
        if (!node) {
            maxInt = max(maxInt, 0);
            return 0;
        }
        int l = depthOfNode(node->left, maxInt);
        int r = depthOfNode(node->right, maxInt);
        maxInt =  max(maxInt, l + r);
        return max(l, r) + 1;
    }
};
