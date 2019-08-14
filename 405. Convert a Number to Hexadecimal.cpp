class Solution {
public:
    string toHex(int num) {
        unordered_map<int, string> hex = {
            {0, "0"}, {1, "1"}, {2, "2"}, {3, "3"}, {4, "4"}, {5, "5"},
            {6, "6"}, {7, "7"}, {8, "8"}, {9, "9"}, {10, "a"}, {11, "b"},
            {12, "c"}, {13, "d"}, {14, "e"}, {15, "f"}
        };
        
        int mask = 0xF;
        int k = 4;
        string res = hex[num & 0xF];
        while ((~mask) & num) {
            res = hex[(num >> k) & 0xF] + res;
            k += 4;
            mask = (mask << 4) + 0xF;
        }
        return res;
    }
};
