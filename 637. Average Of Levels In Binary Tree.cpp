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
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        queue<TreeNode*> nq;
        q.push(root);

        vector<double> res;
        int count = 0;
        double sum = 0;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            count++;
            sum += node->val;
            if(node->left) nq.push(node->left);
            if(node->right) nq.push(node->right);
            if (q.empty()) {
                res.push_back(sum / count);
                count = 0;
                sum = 0;
                swap(q, nq);
            }
        }

        return res;
    }
};
