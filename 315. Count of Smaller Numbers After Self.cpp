class Solution {
private:
    struct Node {
        int val;
        int count = 1;
        int leftCount = 0;
        Node* left;
        Node* right;
    };
    
    int insertTree(Node* root, int val) {
        if (val == root->val) {
            root->count++;
            return root->leftCount;
        }
        
        if (val < root->val) {
            root->leftCount++;
            if (root->left) return insertTree(root->left, val);
            Node* left = new Node();
            left->val = val;
            root->left = left;
            return 0;
        }
        
        if (root->right) return root->leftCount + root->count + insertTree(root->right, val);
        Node* right = new Node();
        right->val = val;
        root->right = right;
        return root->leftCount + root->count;
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) return {};
        reverse(nums.begin(), nums.end());
        vector<int> res = {0};
        Node* root = new Node();
        root->val = nums.front();
        for (int i = 1; i < nums.size(); i++) {
            res.push_back(insertTree(root, nums[i]));
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

/**
class Tree {
    int n;
    vector<int> tree;
public:
    Tree(int size) {
        n = size;
        tree = vector<int>(n + 1, 0);
    }

    void update(int i, int delta) {
        while (i <= n) {
            tree[i] += delta; 
            int lb = i & (-i);
            i += lb;
        }
    }

    int query(int i) {
        int res = 0;
        while (i > 0) {
            res += tree[i];
            int lb = i & (-i);
            i -= lb;
        }
        return res;
    }

};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        set<int> nums2(nums.begin(), nums.end());
        unordered_map<int, int> idx;
        int i = 0;
        for (auto num : nums2) {
            idx[num] = i++;
        }

        Tree freq = Tree(nums2.size());
        vector<int> res;
        reverse(nums.begin(), nums.end());
        for (auto num : nums) {
            i = idx[num];
            res.push_back(freq.query(i));
            freq.update(i + 1, 1);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
**/