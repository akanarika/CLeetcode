/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        int i = 0;
        vector<TreeNode*> bfs = {root};
        while (i < bfs.size() && bfs[i]) {
            bfs.push_back(bfs[i]->left);
            bfs.push_back(bfs[i]->right);
            i++;
        }
        while (i < bfs.size() && !bfs[i]) {
            i++;
        }
        return i == bfs.size();
    }
};

/**
class Solution {
public:
    bool isCompleteTree(TreeNode* root) 
        if (!root) return true;
        
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<TreeNode*, int> m;
        int i = 1;
        m[root] = i++;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
                if (i != m[node] * 2) return false;
                m[node->left] = i++;
            }
            if (node->right) {
                q.push(node->right);
                if (i != m[node] * 2 + 1) return false;
                m[node->right] = i++;
            }
        }
        return true;
    }
};
**/
