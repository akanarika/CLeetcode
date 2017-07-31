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