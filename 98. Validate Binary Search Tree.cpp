/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start
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
    bool isValid(TreeNode* node, int& min, int& max) {
        min = max = node->val;
        if (node->left) {
            int lmax = 0;
            if (!isValid(node->left, min, lmax) || lmax >= node->val) {
                return false;
            }
        }
        if (node->right) {
            int rmin = 0;
            if (!isValid(node->right, rmin, max) || rmin <= node->val) {
                return false;
            }
        }
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        int min = 0;
        int max = 0;
        return isValid(root, min, max);
    }
};
// @lc code=end

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
class Solution {
public:
    bool isValidBST(TreeNode* root) {  
        if (!root) return true;
        int left = 0;
        int right = 0;
        return isValid(root, left, right);
    }
    
private:
    bool isValid(TreeNode* root, int& left, int& right) {
        if (!root) return true;
        left = right = root->val;
        int leftMax = INT_MIN;
        if (root->left && (!isValid(root->left, left, leftMax) || leftMax >= root->val)) {
            return false;
        }
        int rightMin = INT_MAX;
        if (root->right && (!isValid(root->right, rightMin, right) || rightMin <= root->val)) {
            return false;
        }
        return true;
    }
};
**/

/**
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        pair<int, int> mm;
        return minMax(root, mm);
    }

    bool minMax(TreeNode* node, pair<int, int>& mm) {
        pair<int, int> l;
        pair<int, int> r;
        bool lv = true;
        bool rv = true;
        if (node->left) {
            lv = minMax(node->left, l);
        }
        if (node->right) {
            rv = minMax(node->right, r);
        }

        if (lv && rv && (!node->left || l.second < node->val) && (!node->right || r.first > node->val)) {
            mm = make_pair(node->left ? l.first : node->val, node->right ? r.second : node->val);
            return true;
        }

        return false;
    }
};
**/


