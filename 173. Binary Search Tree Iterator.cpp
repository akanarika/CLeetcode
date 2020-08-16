/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> stk;
public:
    BSTIterator(TreeNode* root) {
        while (root) {
            stk.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        if (!hasNext()) return -1;
        TreeNode* node = stk.top();
        int res = node->val;
        stk.pop();
        if (node->right) {
            node = node->right;
            while (node) {
                stk.push(node);
                node = node->left;
            }
        }
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

/**
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
**/
