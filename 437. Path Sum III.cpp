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
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return pathSum(root, {root->val}, sum);
    }

    int pathSum(TreeNode* node, vector<int> path, int sum) {
        if (!node) return 0;
        int res = count(path.begin(), path.end(), sum);
        for (auto child : {node->left, node->right}) {
            if (!child) continue;
            vector<int> newPath;
            newPath.push_back(child->val);
            for (auto v : path) {
                newPath.push_back(v + child->val);
            }
            res += pathSum(child, newPath, sum);
        }
        return res;
    }
};
