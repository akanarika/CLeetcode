class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count = 0;
        unordered_set<char> s;
        for (const auto& c : J) {
            s.insert(c);
        }

        for (const auto& c : S) {
            if (s.find(c) != s.end()) count++;
        }

        return count;
    }
};
