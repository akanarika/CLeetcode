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