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
    unordered_map<TreeNode*, TreeNode*> parent;
    
    void calcParents(TreeNode* node) {
        if (!node) return;
        if (node->left) {
            parent[node->left] = node;
            calcParents(node->left);
        }
        if (node->right) {
            parent[node->right] = node;
            calcParents(node->right);
        }
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        calcParents(root);
        
        // BFS
        vector<TreeNode*> level = {target};
        unordered_set<TreeNode*> seen;
        int step = 0;
        while (!level.empty()) {
            if (step == K) {
                vector<int> res;
                for (auto resnode : level) {
                    res.push_back(resnode->val);
                }
                return res;
            }
            vector<TreeNode*> newLevel;
            for (auto node : level) {
                seen.insert(node);
                for (auto neighbor : {node->left, node->right, parent[node]}) {
                    if (!neighbor || seen.count(neighbor)) continue;
                    newLevel.push_back(neighbor);
                }
            }
            step++;
            level = newLevel;
        }
        return {};
    }
};
