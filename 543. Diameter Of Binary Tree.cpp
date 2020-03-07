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
    int length(TreeNode* node, int& maxDiameter) {
        if (!node) return 0;
        int left = length(node->left, maxDiameter);
        int right = length(node->right, maxDiameter);
        maxDiameter = max(left + right, maxDiameter);
        return max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        length(root, maxDiameter);
        return maxDiameter;
    }
};

/**
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
**/
