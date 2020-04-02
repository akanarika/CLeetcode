/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

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
    unordered_map<TreeNode*, int> depth;
    int countDepth(TreeNode* node) {
        if (!node) return 0;
        depth[node] = 1 + max(countDepth(node->left), countDepth(node->right));
        return depth[node];
    }
    
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth[root] = 0;
        countDepth(root);
        int l = depth[root->left];
        int r = depth[root->right];
        TreeNode* p = root;
        while (l != r) {
            if (l > r) {
                p = p->left;
            } else {
                p = p->right;
            }
            l = p->left ? depth[p->left] : 0;
            r = p->right ? depth[p->right] : 0;
        }
        return p;
    }
};

/**
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root) return NULL;
        unordered_map<TreeNode*, TreeNode*> parent;
        
        vector<TreeNode*> level = {root};
        while (!level.empty()) {
            vector<TreeNode*> newLevel;
            for (const auto& node : level) {
                if (node->left) {
                    newLevel.push_back(node->left);
                    parent[node->left] = node;
                }
                if (node->right) {
                    newLevel.push_back(node->right);
                    parent[node->right] = node;
                }
            }
            if (newLevel.empty()) break;
            level = newLevel;
        }
        
        while (level.size() != 1) {
            vector<TreeNode*> newLevel;
            for (const auto& node : level) {
                if (newLevel.empty() || newLevel.back() != parent[node]) {
                    newLevel.push_back(parent[node]);
                }
            }
            level = newLevel;
        }
        
        return level.back();
    }
};
**/
