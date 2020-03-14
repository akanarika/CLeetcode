/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; i++) {
            int mod3 = i % 3;
            int mod5 = i % 5;
            if (!mod3 && !mod5) res.push_back("FizzBuzz");
            else if (!mod3) res.push_back("Fizz");
            else if (!mod5) res.push_back("Buzz");
            else {
                res.push_back(to_string(i));
            }
        }
        return res;
    }
};
// @lc code=end
