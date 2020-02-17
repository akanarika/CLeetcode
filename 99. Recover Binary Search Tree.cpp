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
    void recoverTree(TreeNode* root) {
        visit(root);
        swap(firstNode->val, secondNode->val);
    }
    
private:
    TreeNode* firstNode;
    TreeNode* secondNode;
    TreeNode* prevNode;
    
    void visit(TreeNode* root) {
        if (!root) return;
        visit(root->left);
        if (prevNode && (prevNode->val >= root->val)) {
            if (!firstNode) firstNode = prevNode;
            secondNode = root;
        }
        prevNode = root;
        visit(root->right);
    }
};