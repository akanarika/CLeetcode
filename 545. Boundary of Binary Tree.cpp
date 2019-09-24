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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return {};

        vector<int> bound;
        vector<TreeNode *> leftB;
        vector<TreeNode *> rightB;
        vector<TreeNode *> leaves;

        leftB.push_back(root);
        rightB.push_back(root);
        getBounds(root, leftB, rightB, leaves);
        reverse(rightB.begin(), rightB.end());
        for (const auto& node : leftB) {
            bound.push_back(node->val);
        }
        for (const auto& node : leaves) {
            bound.push_back(node->val);
        }
        for (const auto& node : rightB) {
            if (node != root) bound.push_back(node->val);
        }
        return bound;
    }

    void getBounds(TreeNode* node, vector<TreeNode *>& leftB, vector<TreeNode *>& rightB, vector<TreeNode *>& leaves) {
        if (node->left) {
            if (node->left->left || node->left->right) {
                if (find(leftB.begin(), leftB.end(), node) != leftB.end()) {
                    leftB.push_back(node->left);
                }
                if (!node->right && find(rightB.begin(), rightB.end(), node) != rightB.end() && find(leftB.begin(), leftB.end(), node) == leftB.end()) {
                    rightB.push_back(node->left);
                }
                getBounds(node->left, leftB, rightB, leaves);
            }
            else leaves.push_back(node->left);
        }
        if (node->right) {
            if (node->right->left || node->right->right) {
                if (find(rightB.begin(), rightB.end(), node) != rightB.end()) {
                    rightB.push_back(node->right);
                }
                if (!node->left && find(leftB.begin(), leftB.end(), node) != leftB.end() && find(rightB.begin(), rightB.end(), node) == rightB.end()) {
                    leftB.push_back(node->right);
                }
                getBounds(node->right, leftB, rightB, leaves);
            }
            else leaves.push_back(node->right);
        }
    }
};
