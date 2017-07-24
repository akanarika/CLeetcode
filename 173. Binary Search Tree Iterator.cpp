/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    TreeNode* curr_node;
    stack<TreeNode* > s;
    
    BSTIterator(TreeNode *root) : curr_node(root){
        while (curr_node) {
            s.push(curr_node);
            curr_node = curr_node->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(curr_node != NULL) curr_node = curr_node->right;
        while (curr_node) {
            s.push(curr_node);
            curr_node = curr_node->left;
        }
        if (s.size() > 0) return true;
        else return false;
    }

    /** @return the next smallest number */
    int next() {
        curr_node = s.top();
        s.pop();
        return curr_node->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */