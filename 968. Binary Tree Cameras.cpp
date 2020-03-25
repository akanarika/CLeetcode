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
    int num;
    // 0 - not covered, 1 - covered, 2 - camera
    int check(TreeNode* node) {
        if (!node) return 1;
        
        int cl = check(node->left);
        int cr = check(node->right);
        if (!cl || !cr) {
            num++;
            return 2;
        }
        if (cl == 2 || cr == 2) {
            return 1;
        }
        return 0;
    }
public:
    int minCameraCover(TreeNode* root) {
        num = 0;
        if (!check(root)) num++;
        return num;
    }
};

/**
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        res = 0;
        if (cover(root) == 0) res++;
        return res;
    }
    
private:
    int res;
    int cover(TreeNode* root) {
        if (!root) return 1;
        int l = cover(root->left);
        int r = cover(root->right);
        if (l == 0 || r == 0) {
            res++;
            return 2;
        }
        if (l == 2 || r == 2) {
            return 1;
        }
        return 0;
    }
};
**/
