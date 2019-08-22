class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        if (label == 1) return {1};

        vector<int> path = {label};
        int b = 0;
        int l = label;
        while (l != 0) {
            l >>= 1;
            b++;
        }
        int least = 1 << (b - 2);
        while (label != 0 && label != 1) {
            label >>= 1;
            label = 3 * least - 1 - label;
            path.insert(path.begin(), label);
            least >>= 1;
        }
        return path;
    }
};
