class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> dict{{1, "I"}, {5, "V"}, 
                                        {10, "X"}, {50, "L"},
                                        {100, "C"}, {500, "D"}, 
                                        {1000, "M"}};
        int bit = 1;
        string s = "";
        while (num != 0) {
            int x = num % 10;
            if (x < 4) for (int i = 0; i < x; i++) s = dict[bit] + s;
            else if (x == 4) s = dict[bit] + dict[bit * 5] + s;
            else if (x == 5) s = dict[bit * 5] + s;
            else if (x > 5 && x < 9) {
                for (int i = 0; i < x - 5; i++) s = dict[bit] + s;
                s = dict[bit * 5] + s;
            } else if (x == 9) s = dict[bit] + dict[bit * 10] + s;
            num /= 10;
            bit *= 10;
        }
        
        return s;
    }
};