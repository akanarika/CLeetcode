class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<int, int> dict = {{0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}};
        
        int i = 0;
        int j = num.size() - 1;
        while (i <= j) {
            int a = num[i] - '0';
            int b = num[j] - '0';
            if (dict.count(a) && dict[a] == b) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }
};
