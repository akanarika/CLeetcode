/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
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
    unordered_map<int, int> freq;
    int maxFreq;
public:
    Solution() {
        maxFreq = 0;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        sumTree(root);
        vector<int> res;
        for (auto f : freq) {
            if (f.second == maxFreq) {
                res.push_back(f.first);
            }
        }
        return res;
    }

    int sumTree(TreeNode* root) {
        if (!root) return 0;
        int sum = root->val + sumTree(root->left) + sumTree(root->right);
        freq[sum]++;
        maxFreq = max(maxFreq, freq[sum]);
        return sum;
    }
};
// @lc code=end
