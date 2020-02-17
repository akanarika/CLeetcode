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
    vector<int> findMode(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        int last = root->val ^ 1;
        int currCount = 0;
        int maxCount = 0;
        find(root, last, currCount, res, maxCount);
        return res;
    }
    
private:
    void find(TreeNode* root, int& last, int& currCount, vector<int>& max, int& maxCount) {
        if (!root) return;
        find(root->left, last, currCount, max, maxCount);
        if (last != root->val) currCount = 0;
        currCount++;
        if (currCount > maxCount) {
            max.clear();
            max.push_back(root->val);
            maxCount = currCount;
        } else if (maxCount == currCount) max.push_back(root->val);
        last = root->val;
        find(root->right, last, currCount, max, maxCount);
    }
};

/**
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if (!root) return {};

        int maxCount = 0;
        int maxEle = INT_MAX;
        int currCount = 0;
        int currEle = INT_MAX;
        visit(root, maxCount, maxEle, currCount, currEle);
        currCount = 0;
        currEle = INT_MAX;
        vector<int> res;
        countAll(root, maxCount, currCount, currEle, res);
        return res;
    }

    void visit(TreeNode* node, int& maxCount, int& maxEle, int& currCount, int& currEle) {
        if (!node) return;

        visit(node->left, maxCount, maxEle, currCount, currEle);
        if (maxEle == INT_MAX) {
            maxEle = node->val;
            maxCount = 1;
            currEle = node->val;
            currCount = 1;
        } else {
            if (currEle == node->val) {
                currCount++;
                if (currCount >= maxCount) {
                    maxCount = currCount;
                    maxEle = currEle;
                }
            } else {
                currCount = 1;
                currEle = node->val;
            }
        }
        visit(node->right, maxCount, maxEle, currCount, currEle);
    }

    void countAll(TreeNode* node, int maxCount, int& currCount, int& lastEle, vector<int>& res) {
        if (!node) return;

        countAll(node->left, maxCount, currCount, lastEle, res);
        if ((lastEle == INT_MAX) || (node->val == lastEle)) {
            currCount++;
        } else {
            currCount = 1;
        }
        lastEle = node->val;
        if (currCount == maxCount) {
            res.push_back(node->val);
        }
        countAll(node->right, maxCount, currCount, lastEle, res);
    }
};
**/
