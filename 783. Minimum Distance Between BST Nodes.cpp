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
    int minDiffInBST(TreeNode* root) {
        int lastMin, lastMax;
        return minDiffInBST(root, lastMin, lastMax);
    }

    int minDiffInBST(TreeNode* root, int& lastMin, int&lastMax) {
        int minDiff = INT_MAX;
        int minLeft = INT_MAX;
        int minRight = INT_MAX;
        lastMin = lastMax = root->val;

        if (root->left) {
            int _lastMax = 0;
            minLeft = minDiffInBST(root->left, lastMin, _lastMax);
            minDiff = min(root->val - _lastMax, minLeft);
        }

        if (root->right) {
            int _lastMin = 0;
            minRight = minDiffInBST(root->right, _lastMin, lastMax);
            minDiff = min(min(_lastMin - root->val, minRight), minDiff);
        }

        return minDiff;
    }
};
