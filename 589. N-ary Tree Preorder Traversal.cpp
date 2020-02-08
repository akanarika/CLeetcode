/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        pre(root);
        return v;
    }

private:
    vector<int> v;
    void pre(Node* node) {
        if (!node) return;
        v.push_back(node->val);
        for (auto child : node->children) {
            pre(child);
        }
    }
};
// @lc code=end
