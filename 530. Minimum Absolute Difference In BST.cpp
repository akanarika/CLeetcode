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
    int getMinimumDifference(TreeNode* root) {
        if (!root) return INT_MAX;

        int minDiff = INT_MAX;
        int last = -1;
        getMinDiff(root, last, minDiff);
        return minDiff;
    }

    void getMinDiff(TreeNode* node, int& last, int& minDiff) {
        if (node->right) getMinDiff(node->right, last, minDiff);
        if (last == -1) last = node->val;
        else {
            minDiff = min(minDiff, last - node->val);
            last = node->val;
        }
        if (node->left) getMinDiff(node->left, last, minDiff);
    }
};
