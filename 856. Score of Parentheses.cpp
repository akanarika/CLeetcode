/*
 * @lc app=leetcode id=856 lang=cpp
 *
 * [856] Score of Parentheses
 */

// @lc code=start
class Solution {
private:
    void sop(istringstream& in, int& score) {
        while (in.peek() != EOF) {
            char c;
            in >> c;
            if (c == '(') {
                if (in.peek() == ')') {
                    score++;
                    in.get();
                } else {
                    int curr = 0;
                    sop(in, curr);
                    score += curr * 2;
                }
            } else {
                return;
            }
        }
    }

public:
    int scoreOfParentheses(string S) {
        istringstream in(S);
        int score = 0;
        sop(in, score);
        return score;
    }
};
// @lc code=end
