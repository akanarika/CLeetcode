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
    bool containOne(TreeNode* root) {
        if (!root) return false;
        bool lc = containOne(root->left);
        bool rc = containOne(root->right);
        if (!lc) root->left = NULL;
        if (!rc) root->right = NULL;
        return root->val || lc || rc;
    }
    
public:
    TreeNode* pruneTree(TreeNode* root) {
        containOne(root);
        return root;
    }
};

/**
class Solution {
private:
    unordered_map<TreeNode*, bool> containNoOne;
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (checkNode(root)) {
            return NULL;
        }
        deleteNode(root);
        return root;
    }

    bool checkNode(TreeNode* node) {
        if (!node) return true;
        bool left = checkNode(node->left);
        bool right = checkNode(node->right);
        bool res = node->val == 0 && left && right;
        containNoOne[node] = res;
        return res;
    }

    void deleteNode(TreeNode* node) {
        if (!node) return;
        if (containNoOne[node->left]) {
            node->left = NULL;
        } else {
            deleteNode(node->left);
        }
        if (containNoOne[node->right]) {
            node->right = NULL;
        } else {
            deleteNode(node->right);
        }
    }
};
**/
