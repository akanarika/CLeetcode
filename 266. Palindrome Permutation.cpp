class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> count(256, 0);
        for (const auto& c : s) {
            count[c]++;
        }
        bool hasOdd = false;
        for (const auto& c : count) {
            if (c % 2 == 1) {
                if (hasOdd) return false;
                hasOdd = true;
            }
        }
        return true;
    }
};
