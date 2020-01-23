/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        istringstream in(str);
        char c;
        int res = 0;
        int sign = 0;
        while (in.peek() != EOF) {
            c = in.get();
            if ((c < '0' || c > '9') && (c != '-' && c != '+' && c != ' ')) break;

            if (c == '-') {
                if (sign == 0) sign = -1;
                else break;
            } else if (c == '+') {
                if (sign == 0) sign = 1;
                else break;
            } else if (c < '0' || c > '9') {
                if (sign == 0) continue;
                else break;
            } else {
                if (sign == 0) sign = 1;
                int num = c - '0';
                if (sign == 1) {
                    if ((INT_MAX - num) / 10 < res) {
                        return INT_MAX;
                    } else {
                        res = res * 10 + num;
                    }
                } else {
                    if ((INT_MIN + num) / 10 > -res) {
                        return INT_MIN;
                    } else {
                        res = res * 10 - 1 + num;
                        if (res == INT_MAX) return INT_MIN;
                        else res++;
                    }
                }
            }
        }
        return res * sign;
    }
};
// @lc code=end

/**
class Solution {
public:
    int myAtoi(string str) {
        if (str == "") return 0;
        int sign = 0;
        int curr_num = 0;
        bool exist = false;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '-') {
                if (sign == 0) sign = -1;
                else return 0;
                exist = true;
            }
            else if (str[i] == '+') {
                if (sign == 0) sign = 1;
                else return 0;
                exist = true;
            }
            else if (str[i] >= '0' && str[i] <= '9') {
                int tmp = curr_num;
                curr_num = curr_num * 10 + str[i] - '0';
                if (curr_num / 10 != tmp) return sign >= 0 ? INT_MAX:INT_MIN;
                exist = true;
            } else if (str[i] == ' ') {
                if (exist) break;
                continue;
            } else {
                if (exist) break;
                return 0;
            }
        }
        if (sign == 0) sign = 1;
        return curr_num * sign;
    }
};
**/
