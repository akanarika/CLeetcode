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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, inorder.size());
    }
    
private:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int s, int e) {
        if (s >= e) return NULL;
        if (s == e - 1) {
            postorder.pop_back();
            return new TreeNode(inorder[s]);
        }
        
        int rval = postorder.back();
        TreeNode* root = new TreeNode(rval);
        int i = s;
        while (i < e) {
            if (inorder[i++] == rval) {
                postorder.pop_back();
                break;
            }
        }
        if (i == e + 1) return NULL;
        root->right = build(inorder, postorder, i, e);
        root->left = build(inorder, postorder, s, i - 1);
        return root;
    }
};
