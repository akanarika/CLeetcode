/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        string last = "";
        return des(in, INT_MIN, INT_MAX, last);
    }
    
private:
    TreeNode* des(istringstream& in, int low, int high, string& last) {
        string s;
        if (!last.empty() || in >> s) {
            int num = last.empty() ? stoi(s) : stoi(last);
            if (num < low || num > high) {
                last = to_string(num);
                return NULL;
            }
            TreeNode* node = new TreeNode(num);
            if (!last.empty()) last.clear();
            node->left = des(in, low, num, last);
            node->right = des(in, num, high, last);
            return node;
        }
        return NULL;
    }
};

/**
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "N";
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return des(in);
    }
    
private:
    TreeNode* des(istringstream& in) {
        string s;
        if (in >> s) {
            if (s == "N") {
                return NULL;
            } else {
                int num = stoi(s);
                TreeNode* left = des(in);
                TreeNode* right = des(in);
                TreeNode* node = new TreeNode(num);
                node->left = left;
                node->right = right;
                return node;
            }
        }
        return NULL;
    }
};
**/

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));