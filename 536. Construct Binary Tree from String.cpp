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
    TreeNode* str2tree(string s) {
        if (s.empty()) return NULL;
        istringstream in(s);
        TreeNode* node = str2tree(in);
        return node;
    }

    TreeNode* str2tree(istringstream& in) {
        int num;
        TreeNode* node;
        if (in >> num) {
            node = new TreeNode(num);
        }
        char c;
        while (in >> c) {
            if ((c == '(') && !node->left) {
                node->left = str2tree(in);
            } else if ((c == '(') && node->left) {
                node->right = str2tree(in);
            } else if (c == ')') break;
        }
        return node;
    }
};
