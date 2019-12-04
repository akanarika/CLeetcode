/*
 * @lc app=leetcode id=299 lang=cpp
 *
 * [299] Bulls and Cows
 */

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        if (secret.empty()) return "0A0B";

        int n = secret.size();
        vector<int> s(10, 0);
        vector<int> g(10, 0);
        int A = 0;
        int B = 0;
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) A++;
            else {
                s[secret[i] - '0']++;
                g[guess[i] - '0']++;
            }
        }
        for (int i = 0; i < 10; i++) {
            B += min(s[i], g[i]);
        }
        
        return to_string(A) + "A" + to_string(B) + "B";
    }
};
// @lc code=end
