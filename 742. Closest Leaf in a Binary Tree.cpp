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
    int findClosestLeaf(TreeNode* root, int k) {
        if (!root) return 0;
        TreeNode* source;
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<TreeNode*, vector<TreeNode*>> m;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->val == k) source = node;
            for (auto cnode : {node->left, node->right}) {
                if (cnode) {
                    m[cnode].push_back(node);
                    m[node].push_back(cnode);
                    q.push(cnode);
                }
            }
        }

        if (!source->left && !source->right) return source->val;

        unordered_set<TreeNode*> visited;
        unordered_map<TreeNode*, int> path;
        pair<TreeNode*, int> res = make_pair(source, INT_MAX);
        q.push(source);
        path[source] = 0;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            for (auto cnode : m[node]) {
                if (visited.find(cnode) == visited.end()) {
                    visited.insert(cnode);
                    q.push(cnode);
                    if (path.find(cnode) == path.end() || path[cnode] > path[node] + 1) {
                        path[cnode] =  path[node] + 1;
                        if (!cnode->left && !cnode->right && (path[cnode] < res.second)) {
                            res = make_pair(cnode, path[cnode]);
                        }
                    }
                }
            }
        }

        return (res.first)->val;
    }
};
