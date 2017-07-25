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
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        calcPath(root, max_sum);
        return max_sum;
    }
private:
    int calcPath(TreeNode* node, int& max_sum) {
        if (node == NULL) return 0;
        int left_sum = calcPath(node->left, max_sum);
        int right_sum = calcPath(node->right, max_sum);
        int curr_sum = node->val + max(max(left_sum, 0), max(right_sum, 0));
        max_sum = max(max_sum, node->val + max(left_sum, 0) + max(right_sum, 0));
        return curr_sum;
    }
};