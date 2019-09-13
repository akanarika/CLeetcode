class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int num = 0;
        unordered_map<string, int> dict{{"", 0}};
        n *= 2;
        while (n > 0) {
            unordered_map<string, int> new_dict;
            for (auto it = dict.begin(); it != dict.end(); it++) {
                if (it->second > 0) {
                    new_dict.insert({it->first + ")", it->second - 1});
                }
                new_dict.insert({it->first + "(", it->second + 1});
            }
            dict = new_dict;
            n--;
        }
        vector<string> res;
        for (auto it = dict.begin(); it != dict.end(); it++) {
            if (it->second == 0) res.push_back(it->first);
        }
        return res;
    }
};
