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
    pair<TreeNode*, TreeNode*> fl(TreeNode* root) {
        if (!root) return make_pair(root, root);
        auto tail = root;
        auto l = root->left;
        auto r = root->right;
        if (l) {
            auto lp = fl(l);
            root->right = lp.first;
            tail = lp.second;
        }
        if (r) {
            auto rp = fl(r);
            tail->right = rp.first;
            tail = rp.second;
        }
        root->left = NULL;
        return make_pair(root, tail);
    }
    
public:
    void flatten(TreeNode* root) {
        fl(root);
    }
};
