class Solution {
public:
    int romanToInt(string s) {
        if (s == "") return 0;
        unordered_map<char, int> dict {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
                                       {'C', 100}, {'D', 500}, {'M', 1000}};
        int res = 0;
        int num = dict[s[0]];
        for (int i = 1; i < s.size(); i++) {
            if (dict[s[i]] > num) res -= num;
            else res += num;
            num = dict[s[i]];
        }
        res += num;
        return res;
    }
};