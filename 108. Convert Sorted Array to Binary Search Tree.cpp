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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeTree(nums, 0, nums.size()-1);
    }
private:
    TreeNode* makeTree(vector<int>& nums, int s, int e) {
        if (s == e) return new TreeNode(nums[s]);
        if (s > e) return NULL;
        int mid = (s + e) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = makeTree(nums, s, mid-1);
        root->right = makeTree(nums, mid+1, e);
        return root;
    }
};