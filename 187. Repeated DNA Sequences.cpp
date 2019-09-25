class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() < 10) return {};

        unordered_map<string, int> dict;
        string curr = s.substr(0, 10);
        dict[curr] = 1;
        vector<string> res;
        for (int i = 10; i < s.length(); i++) {
            curr = curr.substr(1, 9) + s[i];
            dict[curr]++;
            if (dict[curr] == 2) res.push_back(curr);
        }
        return res;
    }
};
