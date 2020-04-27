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
    int fres;
    vector<int> calc(TreeNode* node) {
        int res = 0;
        vector<int> lres = node->left ? calc(node->left) : vector<int>({node->val, node->val, 0});
        vector<int> rres = node->right ? calc(node->right) : vector<int>({node->val, node->val, 0});
        int nmin = min(node->val, min(lres[0], rres[0]));
        int nmax = max(node->val, max(lres[1], rres[1]));
        res = max(max(abs(node->val - lres[0]), abs(node->val - rres[0])),
              max(abs(node->val - lres[1]), abs(node->val - rres[1])));
        fres = max(res, fres); 
        return {nmin, nmax, res};
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        fres = 0;
        calc(root);
        return fres;
    }
};
