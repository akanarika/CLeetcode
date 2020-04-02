class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, unordered_set<char>> children;
        
        for (int i = 0; i < words.size() - 1; i++) {
            string left = words[i];
            string right = words[i + 1];
            int j = 0;
            while (j < left.length() && j < right.length() && left[j] == right[j]) j++;
            if (j < left.length() && j < right.length()) {
                auto fl = find(order.begin(), order.end(), left[j]);
                auto fr = find(order.begin(), order.end(), right[j]);
                if (fl - fr >= 0) return false;
            } else if (j < left.length() && j == right.length()) {
                return false;
            }
        }
        return true;
    }
};
