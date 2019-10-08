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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string s = "";
        while (!q.empty()) {
            TreeNode* u = q.front();
            q.pop();
            s += (u != NULL) ? to_string(u->val) : " ";
            s += ",";
            if (u != NULL) {
                q.push(u->left);
                q.push(u->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return NULL;
        int p = 0;
        vector<TreeNode*> v;
        while (p < data.size()) {
            if (data[p] >= '0' && data[p] <= '9' || data[p] == '-') {
                int curr_num = 0;
                int sign = 1;
                if (data[p] == '-') {
                    sign = -1;
                    p++;
                }
                while (data[p] >= '0' && data[p] <= '9') {
                    curr_num = curr_num * 10 + data[p] - '0';
                    p++;
                }
                TreeNode* node = new TreeNode(sign * curr_num);
                v.push_back(node);
            } else if (data[p] == ' ') {
                TreeNode* node = NULL;
                v.push_back(node);
            }
            p++;
        }
        p = 0;
        int q = 1;
        while (q < v.size()) {
            while (v[p] == NULL) p++;
            v[p]->left = v[q++];
            v[p]->right = v[q++];
            p++;
        }
        return v[0];
    }
};
**/

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
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
        ostringstream os;
        serializeStream(root, os);
        return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        return deserializeStream(is);
    }

private:
    void serializeStream(TreeNode* root, ostringstream& os) {
        if (root) {
            os << root->val << " ";
            serializeStream(root->left, os);
            serializeStream(root->right, os);
        } else {
            os << "# ";
        }
    }

    TreeNode* deserializeStream(istringstream& is) {
        string s;
        if (is >> s) {
            if (s != "#") {
                TreeNode* root = new TreeNode(stoi(s));
                root->left = deserializeStream(is);
                root->right = deserializeStream(is);
                return root;
            } else {
                return NULL;
            }
        }
        return NULL;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
