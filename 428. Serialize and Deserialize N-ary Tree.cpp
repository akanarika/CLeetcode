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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) return "";
        
        string res = to_string(root->val);
        vector<Node*> nodes = {root};
        while (!nodes.empty()) {
            vector<Node*> new_nodes = {};
            for (const auto& node : nodes) {
                res += " " + to_string(node->children.size());
                for (const auto& c : node->children) {
                    res += " " + to_string(c->val);
                    new_nodes.push_back(c);
                }
            }
            nodes = new_nodes;
        }
        return res;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data.empty()) return NULL;
        
        istringstream iss(data);
        int num;
        iss >> num;
        iss.get();
        
        Node* root = new Node(num);
        Node* curr = root;
        queue<Node*> q;
        q.push(root);
        
        while (!iss.eof()) {
            int cnt;
            iss >> cnt;
            while (cnt-- > 0) {
                int num;
                iss >> num;
                Node* node = new Node(num);
                (curr->children).push_back(node);
                q.push(node);
            } 
            q.pop();
            curr = q.front();
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
