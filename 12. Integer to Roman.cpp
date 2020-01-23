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

/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
/**
class Solution {
public:
    string intToRoman(int num) {
        vector<string> one = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        vector<string> two = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> thr = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> fou = {"M", "MM", "MMM"};

        int digit = 1;
        string res = "";
        while (num > 0) {
            int n = num % 10;
            if (n != 0) {
                switch (digit) {
                    case 1:
                        res = one[n - 1] + res;
                        break;
                    case 2:
                        res = two[n - 1] + res;
                        break;
                    case 3:
                        res = thr[n - 1] + res;
                        break;
                    case 4:
                        res = fou[n - 1] + res;
                        break;
                }
            }
            num /= 10;
            digit++;
        }
        return res;
    }
};
**/
// @lc code=end
